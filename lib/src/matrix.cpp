#include"matrix.hpp"

Matrix::Matrix(const std::size_t noRows, const std::size_t noColumns) : Matrix(noRows, noColumns, 0) {}

Matrix::Matrix() : Matrix(10, 10, 0) {}

Matrix::Matrix(const std::size_t noRows, const std::size_t noColumns, const int initial_value):
    noOfRows(noRows), noOfColumns(noColumns) {
    this->matrix.resize(noOfRows);
    for (int i = 0; i < noOfRows; ++i) {
        this->matrix[i].resize(noColumns);
    }
    std::fill(this->matrix.begin(), this->matrix.end(), matrix_row(noColumns,initial_value));
}


/*
Function name: printData
Description: This function prints the matrix on the console.
Function parameters: none
Return value: none
*/ 
void Matrix::printData() const {
    std::cout <<"Printing Matrix::" << std::endl;
    for (int i = 0; i < noOfRows; ++i) {
        for(int j = 0; j < noOfColumns; ++j){
            std::cout<<this->matrix[i][j]<< " ";
        }
        std::cout<<std::endl;
    }
}


/*
Function name: operator*
Description: This function performs matrix with matrix multiplication.
Function parameters: matrix_B: Matrix& (This is the second matrix to be multiplied)
Return value: Matrix 
*/
Matrix Matrix::operator*(Matrix& matrix_B) const throw (char*) {    
    if(this->matrix.empty() || matrix_B.matrix.empty()) throw "Empty matrix";
    
    int noRowsMatB = static_cast<int>(matrix_B.matrix.size());
    int noColumnsMatB = static_cast<int>(matrix_B.matrix[0].size());

    if(noOfColumns != noRowsMatB) throw "Invalid dimensions for matrix multiplication";
    
    Matrix matrix_C(noOfRows, noOfColumns);

    for (int i = 0; i < noOfRows; ++i) {
        for (int j = 0; j < noColumnsMatB; ++j) {
            for (int k = 0; k < noOfColumns; ++k) {
                matrix_C.matrix[i][j] += this->matrix[i][k] * matrix_B.matrix[k][j];
            }
        }
    }

    return matrix_C;
}


/*
Function name: operator*
Description: This function performs scalar with matrix multiplication.
Function parameters: scalar: const int (This is the scalar to be multiplied with the matrix)
Return value: Matrix 
*/
Matrix Matrix::operator*(const int scalar) throw (char*) {    
    Matrix matrix_result(noOfRows, noOfColumns);

    for(int j=0; j<noOfRows; ++j){
        for(int i=0; i<noOfColumns; ++i){
            matrix_result.matrix[i][j] = this->matrix[i][j] * scalar;
        }
    }
    return matrix_result;
}


/*
Function name: operator*
Description: This function performs matrix with vector multiplication.
Function parameters: vector: const Vector& (This is the vector to be multiplied with the matrix)
Return value: Vector 
*/
Vector Matrix::operator*(const Vector& vector) const throw (char*) {
    if(noOfColumns != vector.getSize()) throw "Empty matrix";

    vector_data vector_in = vector.getData();
    vector_data vector_result;

    const int vector_size = vector_in.size();

    if(noOfColumns != vector_size) throw "Invalid dimensions for matrix & vector multiplication";

    for(int i=0; i<noOfRows; ++i)
        vector_result.push_back(std::inner_product(this->matrix[i].begin(), this->matrix[i].end(), 
                vector_in.begin(), 0 , std::plus<int>(), [](int a, int b) {return a * b;}));

    Vector vector_out(vector_result);
    return vector_out;
}


/*
Function name: operator+
Description: This function performs matrix with matrix addition.
Function parameters: matrix_B: const Matrix& (This is the second matrix to be added)
Return value: Matrix 
*/
Matrix Matrix::operator+(const Matrix& matrix_B) const throw (char*) {
    if(noOfRows != matrix_B.getNoRows()) throw "Nonmatching dimensions";
    if(noOfColumns != matrix_B.getNoColumns()) throw "Nonmatching dimensions";
    
    Matrix matrix_C(noOfRows, noOfColumns);
    for(int i=0; i < noOfRows; ++i){
        for(int j=0; j < noOfColumns; ++j){
            matrix_C.matrix[i][j] = this->matrix[i][j] + matrix_B.matrix[i][j];
        }
    }
    return matrix_C;
}


/*
Function name: operator=
Description: This function performs matrix copy.
Function parameters: matrix_B: const Matrix& (This is the matrix to be copied from)
Return value: Matrix 
*/
Matrix Matrix::operator=(const Matrix& matrix_B) {
    noOfRows = matrix_B.matrix.size();
    noOfColumns = matrix_B.matrix[0].size();
    this->matrix.resize(noOfRows);
    for (int i = 0; i < noOfRows; ++i)
        this->matrix[i].resize(noOfColumns);
    this->matrix = matrix_B.matrix;
    return *this;
}