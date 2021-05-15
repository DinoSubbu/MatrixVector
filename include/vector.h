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
        int operator*(Vector &vector_B) const throw (char*);
        void operator*(int scalar) throw (char*);
        Vector operator+(Vector &vector_B) const throw (char*);
        Vector inline operator=(Vector &vector_B);
};

#endif