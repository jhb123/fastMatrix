#include <iostream>
#include <vector>
#include "..\fastMatrix\matrix.h"
#include <time.h>       /* time */



int main() {

	// matricies. A[m][n] have is an m*n matrix n columns and m rows;

	srand(time(NULL));
	matrix<int> M(10,10);
	matrix<int> N(10,10);
	M.print_matrix();
	N.print_matrix();
	M.fill_rand(0,100);
	N.fill_rand(0,100);
	M.print_matrix();
	N.print_matrix();
	matrix<int> foo = M * N;
	foo.print_matrix();

	return 0;
}
