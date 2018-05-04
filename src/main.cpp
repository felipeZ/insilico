
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;
// using arma::mat;
// using arma::randu;

int main(void) {
  mat arr = randu<mat>(4, 4);
  mat brr = randu<mat>(4, 4);

  cout << "result: " << (arr * brr) << endl;

  return(0);

}
