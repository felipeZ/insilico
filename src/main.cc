#include <Eigen/Dense>
#include <iostream>
#include <string>
#include <vector>


using std::cout;


double test_eigen() {
  // auto v1 = Eigen::VectorXd::Random(10);
  // auto v2 = Eigen::VectorXd::Random(10);
  Eigen::Matrix<double, 3, 1> v3{1, 2, 3};
  // Eigen::Matrix<double, 3, 1> v4{4, 5, 6};
  Eigen::Vector3d v4{4, 5, 6};
  cout << "x, y, z: " << v3.x() << "\n";
  return v3.dot(v4);
}

auto main() ->  int
{
  auto r = test_eigen();
  cout << "eigen dot: " << r << "\n";
  
  return(0);
}
