#include"matrix.h"

Matrix Matrix::operator*(Matrix& matrix_B) const throw (char*) {    
    if(this->matrix.empty() || matrix_B.matrix.empty()) throw "Empty matrix";
    
    int noRowsMatA = static_cast<int>(this->matrix.size());
    int noColumnsMatA = static_cast<int>(this->matrix[0].size());
    int noRowsMatB = static_cast<int>(matrix_B.matrix.size());
    int noColumnsMatB = static_cast<int>(matrix_B.matrix[0].size());

    if(noColumnsMatA != noRowsMatB) throw "Invalid dimensions for matrix multiplication";
    
    Matrix matrix_C;
    matrix_C.matrix.resize(noRowsMatA, matrix_row(noColumnsMatB));

    std::vector<int *> columnPtr;
    for(int i=0; i<noRowsMatB; ++i) 
        columnPtr.push_back(&matrix_B.matrix[i][0]);

    for(int j=0; j<noColumnsMatB; ++j){
        for(int i=0; i<noRowsMatA; ++i){
            matrix_C.matrix[i][j] = std::inner_product(this->matrix[i].begin(), this->matrix[i].end(), 
                columnPtr.begin(), 0 , std::plus<int>(), [](int a, int*b) {return a * (*b);});
        }
        std::transform(columnPtr.begin(), columnPtr.end(), columnPtr.begin(), [](int* x) {return ++x;});
    }
    return matrix_C;
}

void Matrix::operator*(const int scalar) throw (char*) {    
    if(this->matrix.empty()) throw "Empty matrix";

    int noRows = static_cast<int>(this->matrix.size());
    int noColumns = static_cast<int>(this->matrix[0].size());

    for(int j=0; j<noRows; ++j){
        for(int i=0; i<noColumns; ++i){
            this->matrix[i][j] *= scalar;
        }
    }
}

Vector Matrix::operator*(const Vector& vector) const throw (char*) {
    // TODO ------------    
    if(this->matrix.empty()) throw "Empty matrix";

    int noRows = static_cast<int>(this->matrix.size());
    int noColumns = static_cast<int>(this->matrix[0].size());

    for(int j=0; j<noRows; ++j){
        for(int i=0; i<noColumns; ++i){
            this->matrix[i][j] *= scalar;
        }
    }
}


Matrix Matrix::operator+(const Matrix& matrix_B) const throw (char*){
    if(this->matrix.size() != matrix_B.matrix.size()) throw "Nonmatching dimensions";
    if(this->matrix[0].size() != matrix_B.matrix[0].size()) throw "Nonmatching dimensions";
    
    Matrix matrix_C;
    for(int i=0; i<this->matrix.size(); ++i){
        for(int j=0; j<this->matrix[0].size(); ++j){
            matrix_C.matrix[i][j] = this->matrix[i][j] + matrix_B.matrix[i][j];
        }
    }
    return matrix_C;
}

Matrix inline Matrix::operator=(const Matrix& matrix_B) {
    this->matrix = matrix_B.matrix;
}