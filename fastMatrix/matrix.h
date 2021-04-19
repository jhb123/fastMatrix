#pragma once
#include <vector>

class matrix{
	public:
		//matricies. A[m][n] have is an m*n matrix n columns and m rows;
		matrix(std::vector < std::vector<int> >);
		matrix(int,int);

		//data strucutre and shape variables
		int rows = 0, cols,numElem;
		std::vector <int> mat;

		//helper functions
		std::vector<int> get_row(int);
		std::vector<int> get_col(int);

		//print functions
		void print_matrix();
		void print_row(int);
		void print_col(int);

};

int dot(std::vector<int>, std::vector<int>);

matrix operator* (matrix, matrix);
