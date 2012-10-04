/* 
 * File:   fuerRausgeben.cpp
 * Author: dickmann
 *
 * Created on September 5, 2012, 11:56 AM
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
    for (int d = 1; d < argc; ++d) {
        string line;
        ifstream myfile(argv[d]);
        int K = 0;
        char name[100];
        int l=0;
        for(l=0;l<strlen(argv[d])-4;++l)
            name[l]=argv[d][l];
        name[l]='\0';
        printf("%s<-c(\n",name);
        if (myfile.is_open()) {
            while (!myfile.eof()) {
                getline(myfile, line);
                char* buffer = new char[line.length()];
                strcpy(buffer, line.c_str());
                if (K != 0 && line.compare("")){
		  printf(",", buffer); 
		  if((K+1)%5==0)
		    printf("\n");
		}
                if (strlen(buffer) > 0) {
                    printf("%s", buffer);
                    K++;
                }
            }
            printf("\n)\n");
            myfile.close();
        } else {
            printf("Kann Datei nicht oeffnen\n");
            exit(0);
        }
    }
    return 0;
}















