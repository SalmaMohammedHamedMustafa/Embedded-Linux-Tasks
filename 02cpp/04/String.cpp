#include <iostream>
#include <cstring>
#include "String.hpp"

// Default constructor
String::String() {
    size = 1; // Size for an empty string (null terminator)
    str = new char[size]; // Allocate memory
    str[0] = '\0'; // Initialize to an empty string
    }
/*parametrized constructor*/
String::String(char *InputStr) {
    this->size = std::strlen(InputStr) + 1;  // get size including null terminator
    this->str = new char[size];               // allocate memory on heap
    std::strcpy(str, InputStr);        // copy the input string
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

/* print the string*/
void String::printS() { std::cout << str << "\n"; }

/*return the size of a string*/
int String::GetSize(const String& obj) const
{
    return obj.size;
}
/*assignment operator overoading with another String object */
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
/*assignment operator overoading with a normal C string */
String& String::operator=(char* InputStr) {
    // Clean before starting
    delete this->str;
    this->size = std::strlen(InputStr) + 1; 
    this->str = new char[size];
    std::strcpy(this->str, InputStr);
    return *this;
}
/*add operator overloading with another String object*/
String String::operator+(const String& obj) const {
    String NewString;
    NewString.size = this->size + obj.size - 1; // Calculate new size
    NewString.str = new char[NewString.size]; // Allocate memory for new string
    std::strcpy(NewString.str, this->str); // Copy current string
    std::strcat(NewString.str, obj.str); // Concatenate the other string
    return NewString; // Return new concatenated string
}

/*add operator overloading with a normal C stye string*/
String String::operator+(char* InputStr) const {
    String NewString;
    NewString.size = this->size + std::strlen(InputStr); // Calculate new size
    NewString.str = new char[NewString.size]; // Allocate memory for new string
    std::strcpy(NewString.str, this->str); // Copy current string
    std::strcat(NewString.str, InputStr); // Concatenate the other string
    return NewString; // Return new concatenated string
}

/*== operator overloadong with another String object */
bool String::operator==(const String& obj) const
{
    return std::strcmp(this->str,obj.str)==0;
}
/*== operator overloadong with another C string*/
bool String::operator==(char* InputStr) const
{
    return std::strcmp(this->str,InputStr)==0;
}
/*!= operator overloadong with another String object */
bool String::operator!=(const String& obj) const
{
    return std::strcmp(this->str,obj.str)!=0;
}
/*!= operator overloadong with another C string*/
bool String::operator!=(char* InputStr) const
{
    return std::strcmp(this->str,InputStr)!=0;
}
// Less than operator
bool String::operator<(const String& obj) const {
    return std::strcmp(this->str, obj.str) < 0;
}

// Greater than operator
bool String::operator>(const String& obj) const {
    return std::strcmp(this->str, obj.str) > 0;
}

// Less than or equal to operator
bool String::operator<=(const String& obj) const {
    return (*this < obj)  || (*this == obj);
}

// Greater than or equal to operator
bool String::operator>=(const String& obj) const {
    return (*this > obj)  || (*this == obj);
}

// Addition assignment operator
String& String::operator+=(const String& obj) {
    int newSize = this->size + obj.size - 1; // Calculate new size
    char* newStr = new char[newSize]; // Allocate memory for concatenated string
    std::strcpy(newStr, this->str); // Copy current string
    std::strcat(newStr, obj.str); // Concatenate the other string

    delete[] this->str; // Clean up old string
    this->str = newStr; // Update to new string
    this->size = newSize; // Update size
    return *this; // Return current object
}