#pragma once

#include "LinReg.h"
#include "alglib/optimization.h"
#include <vector>
#include "util.h"
#include "calibration.h"

using namespace std;

//This class performs linear regression

class LinReg {
public:
	LinReg();
	virtual ~LinReg();

	LinReg(vector<vector<double>> x, vector<double> y, vector<reg_function> f);
	double lin_comb(vector<double> coeff, vector<reg_function> f,
			vector<double>  x);
	double lin_comb( vector<double>  x);

	vector<double> coeff;
	vector<vector<double>> x;
	vector<double> y;
	vector<reg_function> f;
};
