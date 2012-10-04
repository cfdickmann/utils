 
/* 
 * File:   meanvar.cpp
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

    double* x = (double*) malloc(sizeof (double) *(1000000));
    string line;
    ifstream myfile(argv[1]);
    int K = 0;
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, line);
            char * buffer = new char[line.length()];
            strcpy(buffer, line.c_str());
            if (strlen(buffer) > 0) {
                x[K % 1000000] = (double) (atof(buffer));
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
    double quadratsumme;
    for (int i = 0; i < K; ++i)
        quadratsumme += pow(x[i], 2) / (double) (K);
    printf("Anzahl der Werte: %d\n",K);
    printf("mean: %f\n", mean);
    printf("stdev: %f\n", sqrt(quadratsumme - mean * mean)*(double)(K)/(double)(K-1));
}
