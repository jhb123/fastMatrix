#include <iostream>
#include "matrix.cpp"

int main() {
	int foo = 15;
	float bar = 1.5;
	matrix<int> M(foo);
	matrix<float> N(bar);
	std::cout << "Hello, World!\n";
	std::cout<< M.var << std::endl;
	std::cout << N.var << std::endl;
	return 0;
}