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

	matrix<int> M(A);
	matrix<int> N(B);
	M.print_matrix();
	N.print_matrix();
	matrix<int> foo = M * N;
	foo.print_matrix();

	return 0;
}
