
#include <iostream>
#include <armadillo>
#include "H5Cpp.h"
using namespace h5;

using namespace arma;
using namespace std;

// using arma::mat;
// using arma::randu;

auto main() ->  int
{
  mat arr = randu<mat>(4, 4);
  mat brr = randu<mat>(4, 4);

  cout << "result: " << (arr * brr) << endl;

  return(0);
}
