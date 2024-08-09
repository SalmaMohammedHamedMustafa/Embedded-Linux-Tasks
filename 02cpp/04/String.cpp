#include <iostream>
#include <cstring>
#include "String.hpp"

/*parametrized constructor*/
String::String(char *input_str) {
    this->size = std::strlen(input_str) + 1;  // get size including null terminator
    this->str = new char[size];               // allocate memory on heap
    std::strcpy(str, input_str);        // copy the input string
}

/*copy constructor*/
String::String(const String &obj) {
    size = obj.size;
    str = new char[size]; // allocating in heap section respected to the size
    strcpy(str, obj.str); // copy data from obj.str to this->str
}
/*destructor*/
String::~ String()
{
    delete [] str;
    str =nullptr;
}

/*function to print the string*/
void String::printS() { std::cout << str << std::endl; }

String& String::operator=(const String& obj) {

    // Self-assignment check
    if (this == &obj) {
        return *this;
    }
    // Clean before starting
    delete this->str;
    // Deep copy
    this->size = obj.size;
    this->str = new char[size];
    std::strcpy(this->str, obj.str);
    return *this;
}

String& String::operator=(char* input_str) {
    // Clean before starting
    delete this->str;
    this->size = std::strlen(input_str) + 1; 
    this->str = new char[size];
    std::strcpy(this->str, input_str);
    return *this;
}
