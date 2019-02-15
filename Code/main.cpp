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


int main(){
#pragma omp parallel
// Initialise the random array 
	srand(time(NULL));
	int A[N][N];
	int B[N][N];
	int C[N][N] = {};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			A[i][j] = rand()%21;
			B[i][j] = rand()%21;
		}
	}
// Display the arrays
	displayAllArrays(A,B,C);
}
