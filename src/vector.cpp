#include "vector.h"

int Vector::operator*(Vector& vector_B) const throw (char*) {    
    if(this->vector.size() != vector_B.vector.size()) throw "Nonmatching dimensions";
    int result = std::inner_product(this->vector.begin(), this->vector.end(), 
                vector_B.vector.begin(), 0);

    return result;
}

void Vector::operator*(int scalar) throw (char*) {    
    if(this->vector.empty()) throw "Empty vector";
    for(int i=0; i<this->vector.size(); ++i){
        this->vector[i] *= scalar;
    }
}

Vector Vector::operator+(Vector& vector_B) const throw (char*){
    if(this->vector.size() != vector_B.vector.size()) throw "Nonmatching dimensions";
    Vector vector_C;
    for(int i=0; i<this->vector.size(); ++i)
        vector_C.vector[i] = this->vector[i] + vector_B.vector[i];
    return vector_C;
}

Vector inline Vector::operator=(Vector& vector_B) {
    this->vector = vector_B.vector;
}