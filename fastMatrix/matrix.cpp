#include "matrix.h"
#include <iostream>
#include <stdexcept>

matrix::matrix(std::vector < std::vector<int> > mat) {
	this->cols = mat[0].size();
	
	for (auto iter = mat.begin(); iter != mat.end(); ++iter) {
		
		if (iter->size() != cols) {
			throw std::invalid_argument("Not a square matrix");
		};
		this->rows++;
	}
	this-> numElem = this->cols* this->rows;
	this->mat.resize(numElem);

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			this->mat[this->cols *i + j] = mat[i][j];
		}
	}
}

matrix::matrix(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	this->numElem = rows * cols;
	this->mat.resize(this->numElem);
}

matrix::matrix() {
	this->rows = 0;
	this->cols = 0;
	this->numElem = 0;
	this->mat.resize(this->numElem);
}

std::vector<int> matrix::get_row(int row_num) {
	std::vector<int> result(this->cols);
	for (int i = 0; i < this->cols; ++i) {
		result[i] = this->mat[row_num * this->cols + i];
	}
	return result;
}

std::vector<int> matrix::get_col(int col_num) {
	std::vector<int> result(this->rows);
	for (int i = 0; i< this->rows; ++i) {
		result[i] = this->mat[i*this->cols + col_num];
	}
	return result;
}

void matrix::print_row(int row_num) {
	for (int i = row_num*this->cols; i < (row_num+1) * this->cols; ++i) {
		std::cout << this->mat[i] << ' ' ;
	}
	std::cout << std::endl;
}

void matrix::print_col(int col_num) {
	for (int i = 0; i < this->rows ; ++i) {
		std::cout << this->mat[col_num + i*this->rows] << ' ';
	}
	std::cout << std::endl;
}

void matrix::print_matrix() {
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			std::cout << mat[this->cols * i + j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}


int dot(std::vector<int> row, std::vector<int> col) {
	int result = 0;
	for (int i = 0; i < row.size(); ++i) {
		result += row[i] * col[i];
	}
	return result;
}

matrix operator* (matrix A, matrix B) {
	int rows = A.rows;
	int cols = B.cols;
	matrix C = matrix(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; j++) {
			C.mat[cols*i + j] = dot(A.get_row(i), B.get_col(j));
		}
	}
	return C;
}


bool operator == (matrix A, matrix B) {
	return A.mat == B.mat;
}