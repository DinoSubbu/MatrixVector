#include "vector.hpp"
#include "matrix.hpp"

int main(){
    try {
        Matrix matrix_A(2, 2, 2);
        Matrix matrix_B(2, 2, 4);
        (matrix_A + matrix_B).printData();
        (matrix_A * 5).printData();
        (matrix_A * matrix_B).printData();

        Vector vector_A(2, 1);
        Vector vector_B(2, 2);
        (vector_A + vector_B).printData();
        (vector_A * 5).printData();
        std::cout << "Vector-vector multiplication result: " << vector_A * vector_B << std::endl;

        (matrix_A * vector_A).printData();
    }
    catch (char* error_message) {
        std::cout << error_message << std::endl;
    }
   
    return 0;
}