
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
	if (argc == 1) {
		printf("Kein Dateiname angegeben\n");
		exit(0);
	}
	vector<int> vec;
	bool geaendert = false;
	bool simple = false;

	for (int i = 0; i < argc; ++i) {
		string arg = argv[i];
		bool geaendert = false;

		if (!arg.compare("-s")) {
			geaendert = true;
			simple = true;
		}
		if (!geaendert) {
			if (i > 0)
				vec.push_back(i);

			geaendert = true;
		}
		if (i > 0 && !geaendert) {
			printf("Unverständliche Parameter!\n");
			exit(0);
		}
	}

	for (int kk = 0; kk < (int) vec.size(); ++kk) {
		double x[100000];
		string line;
		ifstream myfile(argv[vec.at(kk)]);
		int K = 0;
		if (myfile.is_open()) {
			while (!myfile.eof()) {
				getline(myfile, line);
				char buffer[line.length()];
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
		double quadratsumme = 0;
		for (int k = 0; k < K; ++k)
			quadratsumme += x[k] * x[k] / (double) (K);
		if (!simple) {
			printf(" n: %d ", K);
			printf(" mean: %.5lf, ", mean);
			printf("stdev: %.8lf ",
					sqrt(quadratsumme - mean * mean) * (double) (K)
							/ (double) (K - 1));
			printf(" %s ", argv[vec.at(kk)]);
		} else {
			printf("%.5lf,", mean);
		}
		printf("\n");
		cout.flush();

	}
}

