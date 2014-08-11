
/*
 * initFluidBody can be changed...
 *
 */

#include <iostream>

#define NDEBUG

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/operation_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>

// Must be set if you want to use ViennaCL algorithms on ublas objects
#define VIENNACL_HAVE_UBLAS 1

//
// ViennaCL includes
//
#include "viennacl/linalg/ilu.hpp"
#include "viennacl/linalg/cg.hpp"
#include "viennacl/linalg/bicgstab.hpp"
#include "viennacl/linalg/gmres.hpp"
#include "viennacl/io/matrix_market.hpp"

// Some helper functions for this tutorial:


#include "Random.hpp"
#include "vector-io.hpp"





//#include "GridStag.h"
//#include "Particles.h"



#define VIENNACL_HAVE_UBLAS 1

//using namespace std;

using namespace boost::numeric;
void solvePressureViennacl(float dt) { //keep

	typedef float ScalarType;
  ublas::vector<ScalarType> rhs;
  ublas::vector<ScalarType> result;
  ublas::compressed_matrix<ScalarType> ublas_matrix;

  if (!viennacl::io::read_matrix_market_file(ublas_matrix, "mat65k.mtx"))
  {
    std::cout << "Error reading Matrix file" << std::endl;
    return ;
  }
else{
    std::cout << "reading Matrix file" << std::endl;
}

  if (!readVectorFromFile("rhs65025.txt", rhs))
  {
    std::cout << "Error reading RHS file" << std::endl;
    return ;
  }
else
{
    std::cout << "reading rhs file" << std::endl;
}

//
// Compute ILUT preconditioners for CPU and for GPU objects:
//

viennacl::linalg::ilut_precond<ublas::compressed_matrix<ScalarType> > ublas_ilut(ublas_matrix, viennacl::linalg::ilut_tag());
  std::cout << "----- CG Test -----" << std::endl;

  result = viennacl::linalg::solve(ublas_matrix, rhs, viennacl::linalg::cg_tag());
  //result = viennacl::linalg::solve(ublas_matrix, rhs, viennacl::linalg::cg_tag(1e-6, 20), ublas_ilut);

std::cout<<"CGTESTDOne"<<std::endl;;


return;

}


int main()
{
	solvePressureViennacl(0.2f) ; //keep
	return 0;
}



//---PRESSURE-SOLVER..BRIDSON
