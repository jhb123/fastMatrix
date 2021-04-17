#pragma once
#include <vector>

class matrix{
	public:
		//matricies. A[m][n] have is an m*n matrix n columns and m rows;
		matrix(std::vector < std::vector<int> >);
		void print_matrix();
		int rows = 0,cols;
		std::vector < std::vector<int> > mat;
};

