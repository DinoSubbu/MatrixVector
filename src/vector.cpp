#include "vector.h"

Vector::Vector(const std::size_t size, const int initial_value) {
    this->vector.resize(size);
    std::fill(this->vector.begin(), this->vector.end(), initial_value);
}


/*
Function name: getData
Description: This function returns a copy of the vector.
Function parameters: none
Return value: vector_data
*/ 
vector_data inline Vector::getData() const {
    return this->vector;
}


/*
Function name: getSize
Description: This function returns the size of the vector.
Function parameters: none
Return value: int
*/ 
int inline Vector::getSize() const {
    return this->vector.size();
}


/*
Function name: printData
Description: This function prints the vector on the console.
Function parameters: none
Return value: none
*/ 
void Vector::printData() const {
    std::cout<<"Printing Vector::"<<std::endl;
    for(const auto element: this->vector)
        std::cout<<element<< " ";
    std::cout<<std::endl;
}


/*
Function name: operator*
Description: This function performs vector with vector multiplication.
Function parameters: vector_B: Vector& (This is the second vector to be multiplied)
Return value: int 
*/
int Vector::operator*(Vector& vector_B) const throw (char*) {    
    if(this->vector.size() != vector_B.vector.size()) throw "Nonmatching dimensions";
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
    if(this->vector.empty()) throw "Empty vector";
    for(int i=0; i<this->vector.size(); ++i){
        this->vector[i] *= scalar;
    }
    return this->vector;
}


/*
Function name: operator+
Description: This function performs vector with vector addition.
Function parameters: vector_B: Vector& (This is the second vector to be added)
Return value: Vector 
*/
Vector Vector::operator+(Vector& vector_B) const throw (char*){
    if(this->vector.size() != vector_B.vector.size()) throw "Nonmatching dimensions";
    Vector vector_C;
    for(int i=0; i<this->vector.size(); ++i)
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
    this->vector = vector_B.vector;
}