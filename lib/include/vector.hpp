/*
File name: vector.h
File Description: Implements vector-vector, vector-scalar multiplication and vector-vector addition
Created By: Dinesh Subhuraaj
*/
#ifndef VECTOR_CLASS
#define VECTOR_CLASS

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

typedef std::vector<int> vector_data;

class Vector{
    private:
        vector_data vector;
        int size;
    public:
        Vector();
        Vector(const vector_data vector);
        Vector::Vector(const std::size_t size);
        Vector(const std::size_t size, const int initial_value);
        void resize(const std::size_t size, const int initial_value = 0);

        vector_data inline getData() const {
            return this->vector;
        }
        int inline getSize() const {
            return this->vector.size();
        }
        void printData() const;

        int operator*(Vector &vector_B) const throw (char*);
        Vector operator*(int scalar) throw (char*);
        Vector operator+(Vector &vector_B) const throw (char*);
        Vector operator=(Vector &vector_B);
};

#endif