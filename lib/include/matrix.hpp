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
#include "vector.hpp"

typedef std::vector<std::vector<int>> matrix_data;
typedef std::vector<int> matrix_row;

class Matrix{
    private:
        matrix_data matrix;
        int noOfRows, noOfColumns;
    public:
        Matrix();
        Matrix(const std::size_t noRows, const std::size_t noColumns, const int initial_value);
        Matrix(const std::size_t noRows, const std::size_t noColumns);

        void printData() const;
        std::size_t inline getNoRows() const {
            return this->matrix.size();
        }
        std::size_t inline getNoColumns() const {
            return this->matrix[0].size();
        }

        Matrix operator*(Matrix &matrix_B) const throw (char*);
        Matrix operator*(const int scalar) throw (char*);
        Vector operator*(const Vector& vector) const throw (char*);
        Matrix operator+(const Matrix &matrix_B) const throw (char*);
        Matrix operator=(const Matrix &matrix_B);
};

#endif