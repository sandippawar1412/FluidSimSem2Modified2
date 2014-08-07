#ifndef _HELPER_H
#define _HELPER_H
#include <omp.h>
#include <boost/numeric/ublas/matrix.hpp>
using namespace boost::numeric::ublas;
void copyMat(matrix<double>&, matrix<double>&);
void copyMat(matrix<int>&, matrix<int>&);

#endif
