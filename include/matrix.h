#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include "vector.h"

typedef std::vector<std::vector<int>> matrix_data;
typedef std::vector<int> matrix_row;

class Matrix{
    private:
        matrix_data matrix;
    public:
        Matrix operator*(Matrix &matrix_B) const throw (char*);
        void operator*(const int scalar) throw (char*);
        Vector operator*(const Vector& vector) const throw (char*);
        Matrix operator+(const Matrix &matrix_B) const throw (char*);
        Matrix inline operator=(const Matrix &matrix_B);
};

#endif