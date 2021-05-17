#include "vector.hpp"

Vector::Vector() : Vector::Vector(10, 0) {}

Vector::Vector(const vector_data vector) : vector(vector), size(vector.size()) {}

Vector::Vector(const std::size_t size) : Vector(size, 0) {}

Vector::Vector(const std::size_t size, const int initial_value): size(size) {
    this->vector.resize(size);
    std::fill(this->vector.begin(), this->vector.end(), initial_value);
}


/*
Function name: resize
Description: This function resizes the vector.
Function parameters: none
Return value: none
*/
void Vector::resize(const std::size_t size, const int initial_value) {
    this->size = size;
    this->vector.resize(size);
    std::fill(this->vector.begin(), this->vector.end(), initial_value);
}


/*
Function name: printData
Description: This function prints the vector on the console.
Function parameters: none
Return value: none
*/ 
void Vector::printData() const {
    std::cout<<"Printing Vector::"<<std::endl;
    for(int i=0; i<size; ++i)
        std::cout<<this->vector[i]<< " ";
    std::cout<<std::endl;
}


/*
Function name: operator*
Description: This function performs vector with vector multiplication.
Function parameters: vector_B: Vector& (This is the second vector to be multiplied)
Return value: int 
*/
int Vector::operator*(Vector& vector_B) const throw (char*) {    
    if(size != vector_B.vector.size()) throw "Nonmatching dimensions";
    int result = std::inner_product(this->vector.begin(), this->vector.end(), 
                vector_B.vector.begin(), 0);
    return result;
}


/*
Function name: operator*
Description: This function performs vector with scalar multiplication.
Function parameters: scalar: int (This is the scalar to be multiplied with the vector)
Return value: none 
*/
Vector Vector::operator*(int scalar) throw (char*) {    
    Vector vector_result(size, 0);
    for(int i=0; i<size; ++i){
        vector_result.vector[i] = this->vector[i] * scalar;
    }
    return vector_result;
}


/*
Function name: operator+
Description: This function performs vector with vector addition.
Function parameters: vector_B: Vector& (This is the second vector to be added)
Return value: Vector 
*/
Vector Vector::operator+(Vector& vector_B) const throw (char*){
    if(size != vector_B.getSize()) throw "Nonmatching dimensions";
    Vector vector_C(size, 0);
    for(int i=0; i<size; ++i)
        vector_C.vector[i] = this->vector[i] + vector_B.vector[i];
    return vector_C;
}


/*
Function name: operator=
Description: This function performs vector with vector addition.
Function parameters: vector_B: Vector& (This is the second vector to be added)
Return value: Vector 
*/
Vector Vector::operator=(Vector& vector_B) {
    const std::size_t size = vector_B.getSize();
    this->vector.resize(size);
    this->size = size;
    this->vector = vector_B.vector;
    return *this;
}