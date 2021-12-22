// TODO: Implement this source file
#include "MyString.h"

#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>

using std::ostream;

//default
MyString::MyString(): my_size(0), my_capacity(1), name(new char[my_capacity]{'\0'}){
}
//copy
MyString::MyString(const MyString& str): my_size(str.my_size), my_capacity(str.my_capacity), name(new char[str.my_capacity]){
    for(size_t i = 0; i < my_size; i++){
        name[i] = str.name[i];
    }
    name[my_size] = '\0';
}
//cstring
MyString::MyString(const char* s): my_size(), my_capacity(), name(){
    if(s == nullptr){
        my_size = 0;
        my_capacity = 1;
        name = new char[my_capacity];
        name[0] = '\0';
    }
    else{
        size_t count = 0;
        while(s[count] != '\0'){
            count++;
        }
        my_size = count;
        my_capacity = count + 1;
        name = new char[my_capacity];
        for(size_t i = 0; i < my_size; i++){
            name[i] = s[i];
        }
        name[my_size] = '\0';
    }
}
//destructor
MyString::~MyString(){
    delete[] name;
}
//resize function
void MyString::resize(size_t n){ 
    if(n <= my_size){
        char* temp = new char[n];
        for(size_t i = 0; i < n; i++){
            temp[i]= name[i];
        }
        delete[] name;
        temp[n] = '\0';
        name = temp;
        my_capacity;
        delete[] temp;
    }
    else if(n > my_size){
        char* temp = new char[n];
        for(size_t i = 0; i < my_size; i++){
            temp[i] = name[i];
        }
        temp[my_size] = '\0';
        delete[] name;
        name = temp;
        my_capacity;
        delete[] temp;
    }
}
//capacity
size_t MyString::capacity() const{
    return my_capacity;
}
//size
size_t MyString::size() const{
    return my_size;
}
//length
size_t MyString::length() const{
    return my_size;
}
//data
const char* MyString::data() const{
    if(name == nullptr){
        throw std::invalid_argument("string is nullptr");
    }
    const char* temp = name;
    return temp;
}
//empty
bool MyString::empty()const{
    if(my_size == 0){
        return true;
    }
    return false;
}
//front
const char& MyString::front() const{
    return name[0];
}
//at
const char& MyString::at(size_t pos) const{
    if(pos >= my_size){
        throw std::out_of_range("invalid index");
    }
    return name[pos];
}
//clear
void MyString::clear(){
    my_size = 0;
    name[0] = '\0';
}
//operator <<
ostream& operator << (ostream& os, const MyString& str){
    for(size_t i; i < str.my_size; i++){
        os << str.data()[i];
    }
    return os;
}
//operator =
MyString& MyString::operator=(const MyString& str){
    delete[] name;
    my_capacity = str.my_capacity;
    my_size = str.my_size;
    name = new char[my_capacity];
    for(size_t i = 0; i < my_size; i++){
        name[i] = str.name[i];
    }
    name[my_size] = '\0';
    return *this;
}
//+= operator
MyString& MyString::operator+= (const MyString& str){
    size_t old_size = my_size;
    resize(my_capacity + str.my_capacity);
    my_capacity = str.my_capacity + my_capacity;
    my_size = my_size + str.my_size;
    for(size_t i = old_size; i < my_size; i++){
        name[i] = str.name[i - old_size];
    }
    name[my_size] = '\0';
    return *this;
}
//find
size_t MyString::find(const MyString& str, size_t pos) const {
    bool start = false;
    if(pos >= my_size || my_capacity == 1){
        return -1;
    }
    for(size_t i = pos; i < my_size; i++){
        if(name[i] == str.name[0]){
            start = true;
            for(size_t j = 0; j < str.size(); j++){
                
                if(name[j + i] != str.name[j]){
                    start = false;
                }
            }
            if(start == true){
                return i;
            }
            start = true;
        }
    }
    return -1;
}




