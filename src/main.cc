
// #include <armadillo>
#include <Eigen/Dense>
#include <iostream>
#include <string>
#include <vector>
#include "funtools.h"

// using namespace arma;
// using namespace std;

using std::cout;
using std::endl;
// using arma::mat;
// using arma::randu;

double test_eigen() {
  // auto v1 = Eigen::VectorXd::Random(10);
  // auto v2 = Eigen::VectorXd::Random(10);
  Eigen::Matrix<double, 3, 1> v3{1, 2, 3};
  // Eigen::Matrix<double, 3, 1> v4{4, 5, 6};
  Eigen::Vector3d v4{4, 5, 6};
  cout << "x, y, z: " << v3.x() << endl;
  return v3.dot(v4);
}

auto main() ->  int
{
  // // Armadillo test
  // mat arr = randu<mat>(4, 4);
  // mat brr = randu<mat>(4, 4);
  // cout << "result: " << (arr * brr) << endl;

  // // HDF5 test
  // auto path_dataset = "vector";
  // auto path_file = "/home/felipe/Primer/insilico/data/test.h5";
  // read_data_from_hdf5(path_file, path_dataset);

  // Eigen test
  double x = test_eigen();
  cout << "eigen test: " << x << endl;
  
  return(0);
}
