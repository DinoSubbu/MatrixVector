/*
File name: matrix.h
File Description: Implements matrix-matrix, matrix-vector, matrix-scalar multiplication and matrix-matrix addition
Created By: Dinesh Subhuraaj
*/
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
        Matrix() {}
        Matrix(matrix_data& matrix): matrix(matrix) {}
        Matrix(const std::size_t noRows, const std::size_t noColumns) 
            : Matrix(noRows, noColumns, 0) {}
        Matrix(const std::size_t noRows, const std::size_t noColumns, const int initial_value) {}

        void printData() const;
        std::size_t inline getNoRows() const;
        std::size_t inline getNoColumns() const;

        Matrix operator*(Matrix &matrix_B) const throw (char*);
        Matrix operator*(const int scalar) throw (char*);
        Vector operator*(const Vector& vector) const throw (char*);
        Matrix operator+(const Matrix &matrix_B) const throw (char*);
        Matrix operator=(const Matrix &matrix_B);
};

#endif