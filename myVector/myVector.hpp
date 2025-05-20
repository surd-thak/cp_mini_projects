//if not already declare
#ifndef myVectorHpp
#define myVectorHpp

#include<cstddef> //to use size_t

template<typename T> //generics, why typename token is required

class myVector{
    private:
        // data, size, capacity
        T* data;
        size_t size_;
        size_t capacity;
        size_t assign_capacity(size_t sz);
        void increase_capacity();

    public:
        // constructors
        myVector();
        myVector(size_t given_size, T default_value = T()); //expects T to have a default constructor
        myVector(const myVector& given);
        myVector(myVector&& other);
        ~myVector();

        //member functions
        void push_back(T newItem);
        void pop_back();
        void resize(size_t newSize,T default_value = T());
        bool empty();
        size_t size();


        //operator overloading
        T& operator[] (size_t index);
        myVector<T>& operator= (const myVector<T>& given);
        bool operator== (const myVector& given);
        bool operator< (const myVector& given);
        bool operator> (const myVector& given);
        friend std::ostream& operator<< (std::ostream& os, const myVector<T>& given);


};

#include "myVector.tpp" // ToDo: not give access to tpp file 

#endif

