#include <iostream>
#include <vector>
#include "..\fastMatrix\matrix.h"


int main() {

	// matricies. A[m][n] have is an m*n matrix n columns and m rows;

	std::vector< std::vector<int> > A{
		{1,2},
		{3,4},
	};

	std::vector< std::vector<int> > B{
		{5,6,7},
		{10,8,9},
	};

	std::vector< std::vector<int> > C;

	matrix M(A);
	matrix N(B);
	M.print_matrix();
	N.print_matrix();
	matrix foo = M * N;
	foo.print_matrix();
	//M.print_row(1);
	//M.print_col(1);

	std::cout << (M == N) << std::endl;
	std::cout << (M == M) << std::endl;
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
