
/*
 * File: meanvar.cpp
 * Author: dickmann
 *
 * Created on August 7, 2012, 11:30 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
 if (argc == 1) {
		printf("Kein Dateiname angegeben\n");
		exit(0);
	}

	bool geaendert=false;
	int argnum=6666;
	int laufmax=1;
	for (int i = 0; i < argc; ++i) {
		string arg = argv[i];
		bool geaendert = false;

		if (!arg.compare("-c")) {
			laufmax=1000000;
			geaendert = true;
		}

		if (!geaendert ) {
			argnum=i;
			geaendert = true;
		}

		if (i > 0 && !geaendert){
			printf("Unverständliche Parameter!\n");
			exit(0);
		}
	}

	// if(argnum==6666 || (laufmax=1000000 && argc==1)){
	//   printf("Keine Datei nicht oeffnen\n");
	// exit(0);
	// }

	for(int lauf=1;lauf<=laufmax;++lauf){
		usleep(100000);
		double x [100000];
		string line;
		ifstream myfile(argv[argnum]);
		int K = 0;
		if (myfile.is_open()) {
			while (!myfile.eof()) {
				getline(myfile, line);
				char  buffer [line.length()];
				strcpy(buffer, line.c_str());
				if (strlen(buffer) > 0) {
					x[K % 100000] = (double) (atof(buffer));
					K++;
				}
			}
			myfile.close();
		} else {
			printf("Kann Datei nicht oeffnen\n");
			exit(0);
		}

		double mean = 0;
		for (int i = 0; i < K; ++i)
			mean += x[i] / (double) (K);
		double quadratsumme=0;
		for (int k = 0; k < K; ++k)
			quadratsumme += x[k]*x[k] / (double) (K);


		printf("  n: %d ",K);    printf("  mean: %.3lf,  ", mean);
		printf("stdev: %.5lf  ", sqrt(quadratsumme - mean * mean)*(double)(K)/(double)(K-1));

		if(lauf==laufmax) 
			printf("\n");
		else {
			if(lauf%4==0)printf("/");
			if(lauf%4==1)printf("-");
			if(lauf%4==2)printf("%c",92);
			if(lauf%4==3)printf("|");
			printf("\r");
		}
		cout.flush();
	}
} 



