#include "ImaginaryNumbers.hpp"

// Default constructor
ImaginaryNumbers::ImaginaryNumbers() : real(0), imaginary(0) {
    std::cout << "constructor called\n";
}

// Parameterized constructor
ImaginaryNumbers::ImaginaryNumbers(double r, double i) : real(r), imaginary(i) {
    std::cout << "parameterized constructor called\n";
}

// Destructor
ImaginaryNumbers::~ImaginaryNumbers() {
    std::cout << "Destructor called\n";
}

// Operator overloading for ++obj
ImaginaryNumbers& ImaginaryNumbers::operator++() {
    ++real;
    ++imaginary;
    return *this; // Return the incremented object
}

// Post-increment operator overloading (obj++)
ImaginaryNumbers ImaginaryNumbers::operator++(int) {
    ImaginaryNumbers temp = *this; // Copy current state
    real++;
    imaginary++;
    return temp; // Return the old state
}

// Operator overloading for +
ImaginaryNumbers operator+(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2) {
    return ImaginaryNumbers(num1.real + num2.real, num1.imaginary + num2.imaginary);
}

// Operator overloading for -
ImaginaryNumbers operator-(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2) {
    return ImaginaryNumbers(num1.real - num2.real, num1.imaginary - num2.imaginary);
}

// Operator overloading for <<
std::ostream& operator<<(std::ostream& os, const ImaginaryNumbers& num) {
    os << num.real << " + " << num.imaginary << "i\n";
    return os;
}

// Operator overloading for >>
std::istream& operator>>(std::istream& is, ImaginaryNumbers& num) {
    std::cout << "Enter real part: ";
    is >> num.real;
    std::cout << "Enter imaginary part: ";
    is >> num.imaginary;
    return is;
}