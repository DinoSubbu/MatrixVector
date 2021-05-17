#include"matrix.h"

Matrix::Matrix(const std::size_t noRows, const std::size_t noColumns, const int initial_value) {
    this->matrix.resize(noRows);
    for (int i = 0; i < noRows; ++i)
        this->matrix[i].resize(noColumns);
    std::fill(this->matrix.begin(), this->matrix.end(), matrix_row(noColumns,initial_value));
}


/*
Function name: printData
Description: This function prints the matrix on the console.
Function parameters: none
Return value: none
*/ 
void Matrix::printData() const {
    std::cout<<"Printing Matrix::"<<std::endl;
    for(auto& row: this->matrix){
        for(const auto element: row){
            std::cout<<element<< " ";
        }
        std::cout<<std::endl;
    }
}

/*
Function name: getNoRows
Description: This function returns the number of rows in the matrix.
Function parameters: none
Return value: std::size_t 
*/ 
std::size_t inline Matrix::getNoRows() const {
    return this->matrix.size();
}


/*
Function name: getNoColumns
Description: This function returns the number of columns in the matrix.
Function parameters: none
Return value: std::size_t 
*/ 
std::size_t inline Matrix::getNoColumns() const {
    return this->matrix[0].size();
}


/*
Function name: operator*
Description: This function performs matrix with matrix multiplication.
Function parameters: matrix_B: Matrix& (This is the second matrix to be multiplied)
Return value: Matrix 
*/
Matrix Matrix::operator*(Matrix& matrix_B) const throw (char*) {    
    if(this->matrix.empty() || matrix_B.matrix.empty()) throw "Empty matrix";
    
    int noRowsMatA = static_cast<int>(this->matrix.size());
    int noColumnsMatA = static_cast<int>(this->matrix[0].size());
    int noRowsMatB = static_cast<int>(matrix_B.matrix.size());
    int noColumnsMatB = static_cast<int>(matrix_B.matrix[0].size());

    if(noColumnsMatA != noRowsMatB) throw "Invalid dimensions for matrix multiplication";
    
    Matrix matrix_C;
    matrix_C.matrix.resize(noRowsMatA, matrix_row(noColumnsMatB));

    /*std::vector<int *> columnPtr;
    for(int i=0; i<noRowsMatB; ++i) 
        columnPtr.push_back(&matrix_B.matrix[i][0]);*/

    for(int j=0; j<noColumnsMatB; ++j){
        for(int i=0; i<noRowsMatA; ++i){
            matrix_C.matrix[i][j] = std::inner_product(this->matrix[i].begin(), this->matrix[i].end(), 
                matrix_B.matrix[i].begin(), 0 , std::plus<int>(), [](int a, int*b) {return a * (*b);});
        }
        // std::transform(columnPtr.begin(), columnPtr.end(), columnPtr.begin(), [](int* x) {return ++x;});
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
    if(this->matrix.empty()) throw "Empty matrix";

    const int noRows = static_cast<int>(this->matrix.size());
    const int noColumns = static_cast<int>(this->matrix[0].size());

    for(int j=0; j<noRows; ++j){
        for(int i=0; i<noColumns; ++i){
            this->matrix[i][j] *= scalar;
        }
    }
    return this->matrix;
}


/*
Function name: operator*
Description: This function performs matrix with vector multiplication.
Function parameters: vector: const Vector& (This is the vector to be multiplied with the matrix)
Return value: Vector 
*/
Vector Matrix::operator*(const Vector& vector) const throw (char*) {
    if(this->matrix.empty()) throw "Empty matrix";

    vector_data vector_in = vector.getData();
    vector_data vector_result;

    const int noRowsMat = static_cast<int>(this->matrix.size());
    const int noColumnsMat = static_cast<int>(this->matrix[0].size());
    const int noElementVector = vector_in.size();

    if(noColumnsMat != noElementVector) throw "Invalid dimensions for matrix & vector multiplication";

    for(int i=0; i<noRowsMat; ++i)
        vector_result.push_back(std::inner_product(this->matrix[i].begin(), this->matrix[i].end(), 
                vector_in.begin(), 0 , std::plus<int>(), [](int a, int*b) {return a * (*b);}));

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


/*
Function name: operator=
Description: This function performs matrix copy.
Function parameters: matrix_B: const Matrix& (This is the matrix to be copied from)
Return value: Matrix 
*/
Matrix Matrix::operator=(const Matrix& matrix_B) {
    const std::size_t noRows = matrix_B.getNoRows();
    const std::size_t noColumns = matrix_B.getNoColumns();
    this->matrix.resize(noRows);
    for (int i = 0; i < noRows; ++i)
        this->matrix[i].resize(noColumns);
    this->matrix = matrix_B.matrix;
}