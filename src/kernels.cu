
// Sum two vectors
__global__ void sumArraysOnGPU(float *A, float *B, float *C) {
  int i = threadIdx.x;
  C[i] = A[i] + B[i];
}

void callSumOnGPU(float *dA, float *dB, float *dC) {
  sumArraysOnGPU<<< 1, 1 >>>(dA, dB, dC);  
}
