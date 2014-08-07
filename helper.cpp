
#include "helper.h"

void copyMat(matrix<double>& dest, matrix<double>& src){
	int size2 = (int)src.size2();
	int size1 = (int)src.size1();
	#pragma omp parallel for
	for( int j = 0; j < size2; ++j)
			for( int i = 0; i < size1; ++i) 
				dest(i,j) = src(i,j);
		
}

void copyMat(matrix<int>& dest, matrix<int>& src){
	int size2 = (int)src.size2();
	int size1 = (int)src.size1();
	#pragma omp parallel for
	for( int j = 0; j < size2; ++j)
			for( int i = 0; i < size1; ++i) 
				dest(i,j) = src(i,j);
		
}

