#include <iostream>
#include <ctime>
#include "omp.h"
namespace {
	const auto N = 10;
}

/*** 2D MATRICES ****************************************************************/
void displayArray2D(const int a[N][N]){
	std::cout<<"================================="<<std::endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"================================="<<std::endl;
}

void displayAllArrays2D(const int a[N][N],const int b[N][N],const int c[N][N]){
	std::cout<<"2-DIMENSIONAL MATRICES"<<std::endl;
	std::cout<<"================================="<<std::endl;
	std::cout<<"Input matrix A:"<<std::endl;
	displayArray2D(a);
	std::cout<<"Input matrix B:"<<std::endl;
	displayArray2D(b);
	std::cout<<"Output matrix C: addition"<<std::endl;
	displayArray2D(c);
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

/*** 3D MATRICES ****************************************************************/
void displayArray3D(const int e[N][N][N]){
	std::cout<<"================================="<<std::endl;
	std::cout<<std::endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0; k<N; k++){
				std::cout<<e[i][j][k]<<" ";
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	std::cout<<"================================="<<std::endl;
}

void displayAllArrays3D(const int e[N][N][N],const int f[N][N][N],const int g[N][N][N]){
	std::cout<<"3-DIMENSIONAL ARRAYS"<<std::endl;
	std::cout<<"================================="<<std::endl;
	std::cout<<"Input array E:"<<std::endl;
	displayArray3D(e);
	
	std::cout<<"Input array F:"<<std::endl;
	displayArray3D(f);

	std::cout<<"Output array G: addition"<<std::endl;
	displayArray3D(g);
}

// 3D array addition
void rank3TensorAdd(const int e[N][N][N], const int f[N][N][N], int g[N][N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				g[i][j][k] = e[i][j][k] + f[i][j][k];
			}
		}
	}
}

// 3D array multiplication
void rank3TensorMulti(int e[N][N][N], int f[N][N][N], int g[N][N][N]){
	int temp_e[N][N], temp_f[N][N], temp_g[N][N] = {};
	for(int k=0; k<N; k++){
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				temp_e[i][j] = e[i][k][j];  
				temp_f[j][i] = f[i][j][k];
			}
		}
		rank2TensorMulti(temp_e, temp_f, temp_g);
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++)
				g[k][i][j] = temp_g[i][j];  
		}
	}
}

int main(){
/*** 2D MATRICES ****************************************************************/
// Initialise the random 2D matrices
	srand(time(NULL));
	int A[N][N], B[N][N], C[N][N] = {}, D[N][N] = {};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			A[i][j] = rand()%21;
			B[i][j] = rand()%21;
		}
	}

// 2D matrix addition
	rank2TensorAdd(A,B,C);
// Display the arrays
	displayAllArrays2D(A,B,C);

// 2D matrix multiplication and display of output matrix
	rank2TensorMulti(A,B,D);
	std::cout<<"Output matrix D: multiplication"<<std::endl;
	displayArray2D(D);
	
	std::cout<<std::endl;
	std::cout<<std::endl;

/*** 3D MATRICES ****************************************************************/
// Initialise the random 3D arrays
	srand(time(NULL));
	int E[N][N][N], F[N][N][N], G[N][N][N] = {}, H[N][N][N]={};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				E[i][j][k] = rand()%21;
				F[i][j][k] = rand()%21;
			}
		}
	}
	
// 3D array addition
	rank3TensorAdd(E,F,G);
// Display all the arrays
	displayAllArrays3D(E,F,G);
// 3D array multiplication and display of output array
	rank3TensorMulti(E,F,H);
	std::cout<<"Output array H: multiplication"<<std::endl;
	displayArray3D(H);
}
