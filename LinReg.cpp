#include "LinReg.h"
#include "alglib/optimization.h"
#include "LGSsolver.h"

using namespace alglib;

LinReg::LinReg() {

}

LinReg::LinReg(vector<vector<double>> x, vector<double> y,
		vector<reg_function> f) {
	this->x = x;
	this->f = f;
	this->y = y;
	assert(x.size() == y.size());

	int M = f.size();

	if (x.size() == 0) {
		for (int i = 0; i < M; ++i)
			coeff[i] = 0;
		return;
	}

	//create regression Matrix M^T M
	vector<vector<double>> A(M);
	vector<double> AV(M);
	for (int p = 0; p < M; ++p) {
		A[p] = vector<double>(M);
		for (int q = 0; q < M; ++q)
			A[p][q] = 0.00001 * (double) (p == q);
	}
	for (size_t m = 0; m < y.size(); ++m)
		for (int rr = 0; rr < M; ++rr)
			for (int q = 0; q < M; ++q) {
				double plus = f[rr](x[m]) * f[q](x[m]) / (double) (y.size());
				A[q][rr] += plus;
			}
	for (int rr = 0; rr < M; ++rr) {
		vector<double> erg2(x.size());
		for (size_t m = 0; m < x.size(); ++m)
			erg2[m] = (f[rr](x[m]) * y[m]);
		AV[rr] = meanVec(erg2);
	}

	LGSsolver ls;
	coeff = ls.solve(A, AV);
}

double LinReg::lin_comb(vector<double> x) {
	double sum = 0;
	for (size_t i = 0; i < coeff.size(); ++i)
		sum += coeff[i] * f[i](x);
	return sum;
}

double LinReg::lin_comb(vector<double> coeff, vector<reg_function> f,
		vector<double> x) {

	double sum = 0;
	for (size_t i = 0; i < f.size(); ++i)
		sum += f[i](x) * coeff[i];
	return sum;
}

void fv(const alglib::real_1d_array &x, alglib::real_1d_array &fi, void *ptr) {
	auto R = (LinReg*) (ptr);
	vector<double> koeff(x.length());
	for (size_t i = 0; i < koeff.size(); ++i)
		koeff[i] = x[i];

	for (int i = 0; i < (int) fi.length(); ++i)
		fi[i] = R->lin_comb(koeff, R->f, R->x[i]) - R->y[i];
}

void repp(const alglib::real_1d_array &x, double func, void *ptr) {

}

LinReg::~LinReg() {
}
