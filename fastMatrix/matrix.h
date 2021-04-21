#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

template<class T>
class matrix{
	public:
		//matricies. A[m][n] have is an m*n matrix n columns and m rows;
		matrix(std::vector < std::vector<T> >);
		matrix(int,int);
		matrix();

		//data strucutre and shape variables
		int rows = 0, cols,numElem;
		std::vector <T> mat;

		//helper functions
		std::vector<T> get_row(int);
		std::vector<T> get_col(int);

		//print functions
		void print_matrix();
		void print_row(int);
		void print_col(int);

};

template<class T>
int dot(std::vector<T>, std::vector<T>);

template<class T>
matrix<T> operator* (matrix<T>, matrix<T>);

template<class T>
bool operator == (matrix<T>, matrix<T>);

template<class T>
matrix<T>::matrix(std::vector < std::vector<T> > mat) {
	this->cols = mat[0].size();

	for (auto iter = mat.begin(); iter != mat.end(); ++iter) {

		if (iter->size() != cols) {
			throw std::invalid_argument("Not a square matrix");
		};
		this->rows++;
	}
	this->numElem = this->cols * this->rows;
	this->mat.resize(numElem);

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			this->mat[this->cols * i + j] = mat[i][j];
		}
	}
}

template<class T>
matrix<T>::matrix(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	this->numElem = rows * cols;
	this->mat.resize(this->numElem);
}

template<class T>
matrix<T>::matrix() {
	this->rows = 0;
	this->cols = 0;
	this->numElem = 0;
	this->mat.resize(this->numElem);
}

template<class T>
std::vector<T> matrix<T>::get_row(int row_num) {
	std::vector<int> result(this->cols);
	for (int i = 0; i < this->cols; ++i) {
		result[i] = this->mat[row_num * this->cols + i];
	}
	return result;
}

template<class T>
std::vector<T> matrix<T>::get_col(int col_num) {
	std::vector<int> result(this->rows);
	for (int i = 0; i < this->rows; ++i) {
		result[i] = this->mat[i * this->cols + col_num];
	}
	return result;
}

template<class T>
void matrix<T>::print_row(int row_num) {
	for (int i = row_num * this->cols; i < (row_num + 1) * this->cols; ++i) {
		std::cout << this->mat[i] << ' ';
	}
	std::cout << std::endl;
}

template<class T>
void matrix<T>::print_col(int col_num) {
	for (int i = 0; i < this->rows; ++i) {
		std::cout << this->mat[col_num + i * this->rows] << ' ';
	}
	std::cout << std::endl;
}

template<class T>
void matrix<T>::print_matrix() {
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			std::cout << mat[this->cols * i + j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}

template<class T>
int dot(std::vector<T> row, std::vector<T> col) {
	int result = 0;
	for (int i = 0; i < row.size(); ++i) {
		result += row[i] * col[i];
	}
	return result;
}
template<class T>
matrix<T> operator* (matrix<T> A, matrix<T> B) {
	int rows = A.rows;
	int cols = B.cols;
	matrix<T> C = matrix<T>(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; j++) {
			C.mat[cols * i + j] = dot(A.get_row(i), B.get_col(j));
		}
	}
	return C;
}

template<class T>
bool operator == (matrix<T> A, matrix<T> B) {
	return A.mat == B.mat;
}