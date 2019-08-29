#ifndef INSILICO_H_
#define INSILICO_H_

#include <Eigen/Core>
#include <Eigen/Dense>
#include <cublas_v2.h>
#include <curand.h>

namespace insilico {

// Matrix definition usign col Major for CUDA
template <typename T>
using Mat = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>;

template <typename T>  
// Vector definition
using Vec = Eigen::Matrix<T, Eigen::Dynamic, 1>;
  
// Check Cuda error  
inline cudaError_t checkCuda(cudaError_t result) {
#if defined(DEBUG) || defined(_DEBUG)
  if (result != cudaSuccess) {
    std::cerr << "CUDA Runtime Error: " << cudaGetErrorString(result) << "\n";
  }
#endif
  return result;
}

// CUDA resource manager
template <typename T>
class CudaResources {

public:
  CudaResources() {
    cublasCreate(&_handle);
  }
  CudaResources(bool pinned) : _pinned{pinned} {
    cublasCreate(&_handle);
  }

  // Allocate memory in the device
  void gpu_alloc(T **x, std::size_t n) const {
    (_pinned) ? checkCuda(cudaMallocHost(x, n)) : checkCuda(cudaMalloc(x, n));
  }
  
  // Deallocate memory from the device
  void gpu_free(T *x) const {
    (_pinned) ? checkCuda(cudaFreeHost(x)) : checkCuda(cudaFree(x));
  }

  // Allocate memory in the device, optionally copying the array to the GPU  
  T *initialize_mem_arr(const Vec<T> &xs, bool copy_to_device = true) const;

private:  
  // Cuda variables
  cublasHandle_t _handle;
  bool _pinned = false;
};

template <typename T>
class KernelRunner: public CudaResources<T> {

public:
  void call_kernel() const;
  };

// // Simple Sum of vectors
// void callSumOnGPU(float *dA, float *dB, float *dC);
  
} // namespace insilico

#endif // INSILICO_H_
