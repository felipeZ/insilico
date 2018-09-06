
#include <armadillo>
#include <iostream>
#include <string>
#include <vector>
#include <H5Cpp.h>
#include "funtools.h"
// using namespace arma;
// using namespace std;

using namespace H5;
using std::cout;
using std::endl;
using arma::mat;
using arma::randu;

auto read_float_data_space(
  const DataSet& data_set, const DataSpace& data_space) {
  // Read an Array from HDF5 using the same layout of the file
  // for the container storing the data.
  FloatType float_type = data_set.getFloatType();
  size_t size = float_type.getSize();

  hssize_t rank = data_space.getSimpleExtentNdims();
  hssize_t npoints = data_space.getSimpleExtentNpoints();
  H5S_class_t data_type = data_space.getSimpleExtentType();

  // Get the shape of the array
  hsize_t dims[rank];
  static_cast<void>(data_space.getSimpleExtentDims(dims));

  cout << "Data is " << size * 4 << " bits" << endl;
  cout << "npoints " << npoints << endl;
  cout << "shape: "; 
  for (auto n: dims)
    {cout << " " << n;}
  cout << endl; 

  // Use a container for getting the data from the hdf5 file
  std::vector<double> vec(npoints);
  data_set.read(vec.data(), PredType::NATIVE_DOUBLE, data_space, data_space);

  return(vec);
}

int read_data_from_hdf5(
  const std::string& path_file, const std::string& path_dataset)
{
  H5::H5File file_handler(path_file, H5F_ACC_RDONLY);
  H5::DataSet data_set = file_handler.openDataSet(path_dataset);
  H5T_class_t type_class = data_set.getTypeClass();
  DataSpace data_space = data_set.getSpace();
  if( type_class == H5T_FLOAT) {
    auto vec = read_float_data_space(data_set, data_space);
    cout << "vector: "; 
    for (auto n: vec)
      {cout << " " << n;}
    cout << "\n done!" << endl;

  }  
  file_handler.close();
  return(0);
}

auto main() ->  int
{
  mat arr = randu<mat>(4, 4);
  mat brr = randu<mat>(4, 4);

  cout << "result: " << (arr * brr) << endl;

  auto path_dataset = "vector";
  auto path_file = "/home/felipe/Primer/insilico/data/test.h5";

  int val = read_data_from_hdf5(path_file, path_dataset);
  
  return(0);
}
