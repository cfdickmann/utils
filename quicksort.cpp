#include "quicksort.h"

using namespace std;


//This file contains several small functions
//in order to perform a quicksort

void tausche(double* daten, int * reihe, int i, int k)
{
	double temp = daten[i];
	daten[i] = daten[k];
	daten[k] = temp;

	int temp2 = reihe[i];
	reihe[i] = reihe[k];
	reihe[k] = temp2;
}

int teile(double* daten, int* reihe, int links, int rechts)
{
	int i = links; int j = rechts - 1;
	double pivot = daten[rechts];
	do
	{
		while ((daten[i] <= pivot) && i < rechts)i = i + 1;
		while ((pivot <= daten[j]) && j > links)j = j - 1;
		if (i < j)tausche(daten, reihe, i, j);
	} while (i < j);
	if (!(daten[i] <= pivot))tausche(daten, reihe, i, rechts);
	return i;
}

void quicksort(double* daten, int * reihe, int links, int rechts)
{
	if (links < rechts)
	{
		int teiler = teile(daten, reihe, links, rechts);
		quicksort(daten, reihe, links, teiler - 1);
		quicksort(daten, reihe, teiler + 1, rechts);
	}
}

int* quicksort(double* daten, int* reihe, int l){
	int* reihe2 = new int[l];
	for (int ll = 0; ll < l; ++ll)
		reihe2[ll] = reihe[ll];

	double* daten2 = new double[l];

	for (int ll = 0; ll < l; ++ll)
		daten2[ll] = daten[reihe[ll]];

	quicksort(daten2, reihe2, 0, l - 1);
	delete[] daten2;

	return reihe2;
}

int* quicksort(double* daten, int l){
	int* reihe = new int[l];
	for (int ll = 0; ll < l; ++ll)
		reihe[ll] = ll;

	int* erg = quicksort(daten, reihe, l);
	delete[] reihe;
	return erg;
}

std::vector<size_t> quicksortVec(std::vector<double> v){
	double * dat = new double[v.size()];
	for (int i = 0; i < (int)v.size(); ++i)
		dat[i] = v[i];

	int * res = quicksort(dat, v.size());

	std::vector<size_t> result;
	for (int i = 0; i < (int)v.size(); ++i)
		result.push_back(res[i]);
	delete[] res;
	delete[] dat;
	return result;
}
