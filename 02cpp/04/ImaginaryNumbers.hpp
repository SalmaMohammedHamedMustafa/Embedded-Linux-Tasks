#ifndef IMAGINARYNUMBERS_HPP
#define IMAGINARYNUMBERS_HPP

#include <iostream>

/**
 * @brief Class representing a complex number with a real and imaginary part.
 */
class ImaginaryNumbers {
public:
    double real; /**< The real part of the imaginary number. */
    double imaginary; /**< The imaginary part of the imaginary number. */

    /**
     * @brief Default constructor that initializes the imaginary number to zero.
     */
    ImaginaryNumbers();
    
    /**
     * @brief Parameterized constructor to initialize the imaginary number with given values.
     * @param r The real part.
     * @param i The imaginary part.
     */
    ImaginaryNumbers(double r, double i);
    
    /**
     * @brief Destructor for the ImaginaryNumbers class.
     */
    ~ImaginaryNumbers();
    
    /**
     * @brief Pre-increment operator overloading (++obj).
     * @return A reference to the incremented object.
     */
    ImaginaryNumbers& operator++();
    
    /**
     * @brief Post-increment operator overloading (obj++).
     * @param int Dummy parameter to distinguish from pre-increment.
     * @return A copy of the object before incrementing.
     */
    ImaginaryNumbers operator++(int);
    
    /**
     * @brief Friend function to overload the + operator.
     * @param num1 The first imaginary number.
     * @param num2 The second imaginary number.
     * @return A new imaginary number that is the sum of num1 and num2.
     */
    friend ImaginaryNumbers operator+(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2);
    
    /**
     * @brief Friend function to overload the - operator.
     * @param num1 The first imaginary number.
     * @param num2 The second imaginary number.
     * @return A new imaginary number that is the difference of num1 and num2.
     */
    friend ImaginaryNumbers operator-(const ImaginaryNumbers& num1, const ImaginaryNumbers& num2);
    
    /**
     * @brief Friend function to overload the << operator for output.
     * @param os The output stream.
     * @param num The imaginary number to output.
     * @return The modified output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const ImaginaryNumbers& num);
    
    /**
     * @brief Friend function to overload the >> operator for input.
     * @param is The input stream.
     * @param num The imaginary number to input.
     * @return The modified input stream.
     */
    friend std::istream& operator>>(std::istream& is, ImaginaryNumbers& num);
};

#endif // IMAGINARYNUMBERS_HPP