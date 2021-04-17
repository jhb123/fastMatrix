#include "matrix.h"
#include <iostream>
#include <stdexcept>

matrix::matrix(std::vector < std::vector<int> > mat) {
	this->mat = mat;
	this->cols = mat[0].size();
	
	for (auto iter = mat.begin(); iter != mat.end(); ++iter) {
		
		if (iter->size() != cols) {
			throw std::invalid_argument("Not a square matrix");
		};
		this->rows++;
	}

}

void matrix::print_matrix() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}