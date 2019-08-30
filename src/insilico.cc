#include "insilico.hpp"
#include "kernels.cuh"
#include <iostream>

namespace insilico {

// Allocate memory in the device, optionally copying the array to the GPU
template<typename T>
T *CudaResources<T>::initialize_mem_arr(const Vec<T> &A, bool copy_to_device) const {
  // size of the array
  std::size_t size_A = A.size() * sizeof(T);

  // Pointer in the device
  T *dA;

  // Allocate either pageable or pinned memory
  gpu_alloc(&dA, size_A);

  // Transfer data to the GPU
  if (copy_to_device) {
    // Pointers at the host
    const T *hA = A.data();
    checkCuda(cudaMemcpy(dA, hA, size_A, cudaMemcpyHostToDevice));
  }
  return dA;
}
  
// Call a kernel
template <typename T>
void KernelRunner<T>::call_kernel() const {  

  // Input vectors
  int dim = 24;
  Vec<T> xs = Vec<T>::Random(dim);
  Vec<T> ys = Vec<T>::Random(dim);  

  // Copy memory in the device
  T *dA = this -> initialize_mem_arr(xs);
  T *dB = this -> initialize_mem_arr(ys);
  T *dC = this -> initialize_mem_arr(xs, false);

  auto grids = 1;
  auto blocks = dim;
  callSumOnGPU<T>(dA, dB, dC, grids, blocks);

  // vector with the result
  Vec<T> zs = Vec<T>::Zero(dim);
  T *hz = zs.data();
  size_t size_C = zs.size() * sizeof(T);
  
  // copy array back to the device  
  checkCuda(cudaMemcpy(hz, dC, size_C, cudaMemcpyDeviceToHost));
  // Deallocate memory from the device
  this -> gpu_free(dA);
  this -> gpu_free(dB);
  this -> gpu_free(dC);

  std::cout << "results: " << zs << "\n";
}


// explicit instantiations
template class CudaResources<float>;
template class CudaResources<double>;  
// template class KernelRunner<float>;
template class KernelRunner<double>;

} 


