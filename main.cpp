#include "vector.h"
#include "matrix.h"

int main(){
    Matrix matrix_A(10, 10, 2);
    Matrix matrix_B(10, 10, 4);
    Matrix matrix_C = matrix_A + matrix_B;
    matrix_C.printData();

    matrix_C = matrix_A * 5;
    matrix_C.printData();

    matrix_C = matrix_A * matrix_B;
    matrix_C.printData();

    Vector vector_A(10, 1);
    Vector vector_B(10, 2);
    Vector vector_C = vector_A + vector_B;
    vector_C.printData();

    vector_C = vector_A * 5;
    vector_C.printData();

    const int result = vector_A * vector_B;
    std::cout << result << std::endl;

    vector_C = matrix_A * vector_A;
    vector_C.printData();

    return 0;
}