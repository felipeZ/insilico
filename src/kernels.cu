
// Sum two vectors
template <typename T>
__global__ void sumArraysOnGPU(T *A, T *B, T *C) {
  int i = threadIdx.x;
  C[i] = A[i] + B[i];
}

template <typename T>
void callSumOnGPU(T *dA, T *dB, T *dC, int grids, int blocks) {
  sumArraysOnGPU<<< grids, blocks >>>(dA, dB, dC);  
}

// Instantiate the kernel template
template void callSumOnGPU<float>(float *dA, float *dB, float *dC, int m, int n);
template void callSumOnGPU<double>(double *dA, double *dB, double *dC, int m, int n);