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
    public:
        Vector() {}
        Vector(vector_data& vector): vector(vector) {}
        Vector(const std::size_t size, const int initial_value) {}

        vector_data inline getData() const;
        int inline getSize() const;
        void printData() const;

        int operator*(Vector &vector_B) const throw (char*);
        Vector operator*(int scalar) throw (char*);
        Vector operator+(Vector &vector_B) const throw (char*);
        Vector operator=(Vector &vector_B);
};

#endif