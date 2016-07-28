#pragma once

#include <vector>

using namespace std;


//This class just solves a linear equation system
//by calling the boost routines
//and perform a triangular decomposition

class LGSsolver {
public:
	LGSsolver();
	virtual ~LGSsolver();
	vector<double> solve(vector<vector<double>> AA,vector<double>  bb);
};
