// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>

using std::ostream;


class MyString{
    public:
        //constructor
            //defult
        MyString();
            //copy
        MyString(const MyString& str);
            //cstring
        MyString(const char* s);
        //destructor
        ~MyString();
        //resize string to n
        void resize(size_t n);
        //capacity
        size_t capacity() const ;
        //size
        size_t size() const ;
        //length
        size_t length() const ;
        //data
        const char* data() const ;
        //empty
        bool empty() const;
        //front
        const char& front() const;
        //at
        const char& at(size_t pos) const;
        //clear
        void clear();
        //operator <<
        friend ostream& operator<< (ostream& os, const MyString& str);
        //operator =
        MyString& operator = (const MyString& str);
        //+= operator
        MyString& operator+= (const MyString& str);
        //find
        size_t find(const MyString& str, size_t pos = 0) const;
    

    private:
        size_t my_size;
        size_t my_capacity;
        char* name;

};

#endif