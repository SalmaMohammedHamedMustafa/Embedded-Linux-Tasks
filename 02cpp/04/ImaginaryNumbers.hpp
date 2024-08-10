#ifndef IMAGINARYNUMBERS_HPP
#define IMAGINARYNUMBERS_HPP

#include <iostream>

class ImaginaryNumbers {
public:
    double real;
    double imaginary;

    // Default constructor
    ImaginaryNumbers();
    
    // Parameterized constructor
    ImaginaryNumbers(double r, double i);
    
    // Destructor
    ~ImaginaryNumbers();
    
    // Pre-increment operator overloading (++obj)
    ImaginaryNumbers& operator++();
    
    // Post-increment operator overloading (obj++)
    ImaginaryNumbers operator++(int);
    
    // Friend function to overload the + operator
    friend ImaginaryNumbers operator+(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2);
    
    // Friend function to overload the - operator
    friend ImaginaryNumbers operator-(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2);
    
    // Friend function to overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const ImaginaryNumbers& num);
    
    // Friend function to overload the >> operator
    friend std::istream& operator>>(std::istream& is, ImaginaryNumbers& num);
};

#endif // IMAGINARYNUMBERS_HPP