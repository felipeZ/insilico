#include "insilico.hpp"
#include <Eigen/Dense>
#include <iostream>
using std::cout;

auto main() -> int {
  insilico::KernelRunner<double> KR;
  KR.call_kernel();

  return (0);
}
