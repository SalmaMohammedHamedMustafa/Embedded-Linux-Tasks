#include "ImaginaryNumbers.hpp"

int main() {
    ImaginaryNumbers number1;
    ImaginaryNumbers number2;
    ImaginaryNumbers summation;
    ImaginaryNumbers Diff;

    std::cin >> number1;
    std::cin >> number2;
    
    summation = number1 + number2;
    Diff = number1 - number2;
    
    std::cout << "Summation: " << summation << std::endl;
    std::cout << "Difference: " << Diff << std::endl;
    
    ++summation;
    ImaginaryNumbers temp = summation++;
    
    std::cout << "After increment:\n";
    std::cout << "Summation: " << summation;
    std::cout << "Temp: " << temp;

    return 0;
}