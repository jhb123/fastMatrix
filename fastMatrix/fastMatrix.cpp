#include <iostream>
#include <vector>
#include "matrix.h"

template<class T>
std::vector < std::vector<T> > matrix_multiply(
	std::vector < std::vector<T> > A, std::vector < std::vector<T> > B);

template<class T>
void print_matrix(T M);

int main() {

	// matricies. A[m][n] have is an m*n matrix n columns and m rows;

	std::vector< std::vector<int> > A {
		{1,2},
		{3,4},
	};
	
	std::vector< std::vector<int> > B{
		{5,6,7},
		{7,8,9},
	};
	std::vector< std::vector<int> > C;


	try {
	C = matrix_multiply(A, B);
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
	print_matrix(A);
	print_matrix(B);
	print_matrix(C);

	matrix M(A);
	M.print_matrix();
	//std::cout <<  << std::endl;


	return 0;
}







template<class T>
std::vector < std::vector<T> > matrix_multiply(
	std::vector < std::vector<T> > A, std::vector < std::vector<T> > B) {
	// variables for storing the shape of the matricies.
	// matricies. A[m][n] have is an m*n matrix n columns and m rows;
	int n1 = A[0].size(), m1 = 0, n2 = B[0].size(), m2 = 0;

	//first check the rows of each matrix have the same length
	for (auto iter = A.begin(); iter != A.end(); ++iter) {
		if (iter->size() != n1) {
			throw std::invalid_argument("Matrix 1 shape is not rectangular");
		};
		++m1;
	}

	for (auto iter = B.begin(); iter != B.end(); ++iter) {
		if (iter->size() != n2) {
			throw std::invalid_argument("Matrix 2 shape is not rectangular");
		};
		++m2;
	}

	//check that the matricies are the right shape to be multiplied together
	if (n1 != m2) {
		throw std::invalid_argument("Matricies cannot be multiplied");
	};

	//create a vector of the right size
	// matricies. A[m][n] have is an m*n matrix n columns and m rows,
	// so result's shape is m1*n2
	std::vector < std::vector<T> > result(m1, std::vector<T>(n2));
	for (int i = 0; i < m1; ++i) {
		for (int j = 0; j < n2; ++j) {
			for (int k = 0; k < n1; ++k) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return result;
}

template<class T>
void print_matrix(T M) {
	int m1 = M[0].size(), n1 = M.size();
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < m1; ++j) {
			std::cout << M[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
