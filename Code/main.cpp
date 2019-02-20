#include <iostream>
#include <ctime>
#include "omp.h"
namespace {
	const auto N = 10;
}

void displayArray(const int a[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

void displayAllArrays(const int a[N][N],const int b[N][N],const int c[N][N]){
	std::cout<<"A:"<<std::endl;
	displayArray(a);
	std::cout<<"B:"<<std::endl;
	displayArray(b);
	std::cout<<"C:"<<std::endl;
	displayArray(c);
}

// 2D matrix addition
void rank2TensorAdd(const int a[N][N], const int b[N][N], int c[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			c[i][j] = a[i][j] + b[i][j];
			}
		}
	}

// 2D matrix multiplication
void rank2TensorMulti(const int a[N][N], const int b[N][N], int c[N][N]){
	for(int k=0; k<N; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				c[i][j] = c[i][j] + a[i][k]*b[k][j];
			}
		}
	}
}

int main(){
// Initialise the random array 
	srand(time(NULL));
	int A[N][N];
	int B[N][N];
	int C[N][N] = {};
	int D[N][N] = {};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			A[i][j] = rand()%21;
			B[i][j] = rand()%21;
		}
	}

// 2D matrix addition
	rank2TensorAdd(A,B,C);
// Display the arrays
	displayAllArrays(A,B,C);

// 2D matrix multiplication and display of output matrix
	rank2TensorMulti(A,B,D);
	std::cout<<"D: "<<std::endl;
	displayArray(D);
}
