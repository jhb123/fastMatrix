#pragma once
template<class T>
class matrix {
public:
	matrix(T);
	T var;
	T get_var();
};

template<class T>
matrix<T>::matrix(T UserVar) {
	this->var = UserVar;
}

template<class T>
T matrix<T>::get_var() {

	return this->var;
}

