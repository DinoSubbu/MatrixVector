#include "vector.h"
#include "matrix.h"

int main(){
    Matrix matrix_A(4096, matrix_row(4096,4));
    Matrix matrix_B(4096, matrix_row(4096,4));
    std::cout<<"Output Matrix-->"<<std::endl;
    Matrix matmultiplier;
    Matrix matrix_C = matrix_A * matrix_B;
    for(auto row: matrix_C){
        for(const auto element: row){
            std::cout<<element<< " ";
        }
        std::cout<<std::endl;
    }
    return 0;
}