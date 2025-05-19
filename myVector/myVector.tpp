#ifndef myVectorTpp
#define myVectorTpp

#include <iostream>
#include "myVector.hpp"



//default constructor
template<typename T>
myVector<T>::myVector(){
    data = nullptr;
    size_ = 0;
    capacity = 0;
}

//parameterized constructor
template<typename T>
myVector<T>::myVector(size_t given_size, T default_value = T()){
    capacity = assign_capacity(size_);
    data = new T[capacity]; size_ = given_size; 
    for(size_t sz = 0; sz< size_; ++sz)data[sz] = T();
}

//copy constructor
template<typename T>
myVector<T>::myVector(const myVector<T>& given){
    size_ = given.size();
    capacity = assign_capacity(size_)
    data = new T[capacity]
    for(size_t sz = 0; sz < size_; ++sz)data[sz] = given[sz];
}

//move constructor
template<typename T>
myVector<T>::myVector(myVector<T>&& other){
    size_ = other.size_;
    capacity = other.capacity;
    data = other.data;
    
    other.data = nullptr;
    other.size() = 0;
}

//destructor
template<typename T>
myVector<T>::~myVector(){
    delete[] data;
}

//assign capacity
template<typename T>
size_t myVector<T>::assign_capacity(size_t sz){
    if(sz == 0)return 0;
    size_t cap = 1;
    while(cap < sz){
        cap = cap << 1;
    }
    return cap;
}

//increase capacity
template<typename T>
void myVector<T>::increase_capacity(){ 
    if(!capacity) capacity = 1;
    else capacity << 1;
}


template<typename T>
void myVector<T>::push_back(T newItem){
    if(size_ == capacity){
        increase_capacity();

    }
    data[size_] = newItem;
    size_++;
}

template<typename T>
void myVector<T>::pop_back(){
    if(size_== 0){
        throw std::out_of_range("Index out of bounds");
    }
    size_--;
    delete data[size_];
}

template<typename T>
void myVector<T>::resize(size_t newSize,T default_value = T()){
    if(newSize > size_){
        if(newSize <= capacity){
            for(size_t sz = size_; sz < newSize; sz++){
                data[sz] = default_value;
            }
        }else{
            size_t newCapacity =  capacity * 2;
            T* newData = new T[newCapacity];

            for (size_t i = 0; i < size_; ++i) {
                newData[i] = std::move(data[i]);
            }

            for (size_t i = size_; i < newSize; ++i) {
                newData[i] = default_value;
            }

            delete[] data;

            data = newData;
            capacity = newCapacity;
        }

    }else{
        for(size_t sz = size_; size_ > newSize; sz--){
            data[sz-1].~T();
        }
    }
    size_ = newSize;
}

template<typename T>
bool myVector<T>::empty(){
    if(size_==0)return true;
    return false;
}



template<typename T>
T& myVector<T>:: operator[] (size_t index){ //not considered const vector
    if(index >= size_)  throw std::out_of_range("Index out of bounds");
    return data[index]; //by reference
}

template<typename T>
void myVector<T>:: operator= (const myVector<T>& given){
    delete data[];
    size_ = given.size_;
    capacity = given.capacity;
    T* newData = new T[capacity];
    for(size_t sz = 0; sz < size_; sz++)newData[sz] = given[sz];
    data = newData;
}

template<typename T>
bool myVector<T>:: operator== ( const myVector& given){
    if(size_!=given.size())return false;
    for(size_t sz = 0; sz < size_; sz++){
        if(data[sz]!=given[sz])return false;
    }
    return true;
}

template<typename T>
bool myVector<T>:: operator< (const myVector& given){
    return (int) size_ < (int) given.size;
}

template<typename T>
bool myVector<T>:: operator> (const myVector& given){
     return (int) size_ > (int) given.size;
}

template<typename T>
std::ostream& operator<< (std::ostream& os, const myVector<T>& given){
    os << "[ ";
    for (size_t i = 0; i < vec.size_; ++i) {
        os << vec.data[i];
        if (i < vec.size_ - 1) os << ", ";
    }
    os << " ]";
    return os;
}


#endif