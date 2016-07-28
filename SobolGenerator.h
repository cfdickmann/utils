#pragma once

#include <vector>
#include "util.h"

//This class generates Brownian Increments
//based on sobol points.

class SobolGenerator {
private:
	//Thsi parameters stores the current number of the last sobol point
	int sobol_index_;

	//This is the original function from Frances Kuo
	double **sobol_points_kuo(unsigned N, unsigned D, char *dir_file) ;

public:

	//This function delegates the work to the function before
	vector<vector<double> > sobol_numbers(int N, int D);

	SobolGenerator();

	//sets the seed
	void setSeed(long seed);
	void setSeedTime(long seed);

	//This is the main function called from outside
	void nextNormals(vector<Normals> &nor);
};
