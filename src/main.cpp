
#include <armadillo>
#include <iostream>
#include <string>
#include <vector>
#include "H5Cpp.h"

// using namespace arma;
// using namespace std;

using namespace H5;
using arma::mat;
using arma::randu;
using std::cout;
using std::endl;


int read_data_from_hdf5(const std::string& path_file, const std::string& path_dataset)
{
  H5::H5File file_handler(path_file, H5F_ACC_RDONLY);
  H5::DataSet dataset = file_handler.openDataSet(path_dataset);
  H5T_class_t type_class = dataset.getTypeClass();
  file_handler.close();
  
  cout << "Data store in the file: " << type_class << endl;
  return(0);
}

auto main() ->  int
{
  mat arr = randu<mat>(4, 4);
  mat brr = randu<mat>(4, 4);

  cout << "result: " << (arr * brr) << endl;

  auto path_dataset = "ethylene/point_0/cp2k/mo/eigenvalues";
  auto path_file = "/home/felipe/Primer/insilico/data/ethylene.hdf5";

  int val = read_data_from_hdf5(path_file, path_dataset);
  
  return(0);
}
