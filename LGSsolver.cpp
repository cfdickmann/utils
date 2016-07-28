#include "LGSsolver.h"
#include <vector>
#include <stdlib.h>
#include <math.h>
#include "util.h"
#include <boost/numeric/ublas/lu.hpp>

using namespace std;
namespace ublas = boost::numeric::ublas;

LGSsolver::LGSsolver() {
}

LGSsolver::~LGSsolver() {
}

vector<double> LGSsolver::solve(vector<vector<double>> AA, vector<double> bb) {

	ublas::matrix<double> A(AA.size(), AA[0].size());
	for (size_t i = 0; i < AA.size(); ++i)
		for (size_t k = 0; k < AA[0].size(); ++k)
			A(i, k) = AA[i][k];

	auto y = to_ublas_vector(bb);

	ublas::permutation_matrix<size_t> pm(A.size1());
	lu_factorize(A, pm);
	lu_substitute(A, pm, y);
	return to_std_vector(y);
}
