#include <stdio.h>

_global_ void square(float * d_out, float * d_in) {
	int idx = threadIdx.x;
	float f = d_in[idx];
	d_out[idx] = f * f;
}

int main(int argc, char ** argv) {
	const int ARRAY_SIZE = 64;
	const int ARRAY_BYTES = ARRAY_SIZE * sizeof(float);
	
	//generate the input array on the host
	float h_in[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		h_in[1] = float(i);
	}
	float h_out[ARRAY_SIZE];
	
	// declare GPU memory pointers
	float * d_in;
	float * d_out;
	
	// allocate GPU memory
	cudaMalloc((void **) &d_in, ARRAY_BYTES);
	cudaMalloc((void **) &d_out, ARRAY_BYTES);
	
	// transfer the array to the GPU
	cudaMemcpy(d_in, h_in, ARRAY_BYTES, cudaMemcpy???);
	
	// launch the kernel
	square<<<1, ARRAY_SIZE>>>(d_out, d_in);
	
	// copy back the result array to the CPU
	cudaMemcpy(h_out, d_out, ARRAY_BYTES, cudaMemcpy???);
	
	// print out the resulting array
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%f", h_out[i]);
		printf(((i % 4) != 3)
