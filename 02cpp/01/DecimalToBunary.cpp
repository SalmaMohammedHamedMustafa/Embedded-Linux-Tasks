#include <iostream>
#include <bitset>
#include <string>

const int BITSET_SIZE = 8;
 
std::bitset<BITSET_SIZE>  DecimalToBinary (int Number)
{
    std::bitset<BITSET_SIZE> binary(Number);
    return binary;
}

unsigned long BinaryToDecimal (std::string Binary)
{
    std::bitset<BITSET_SIZE> binary(Binary);
    unsigned long decimalNumber = binary.to_ulong();
    return decimalNumber;
}

int main() {


    
    int choice;
    std::cout << "Choose conversion type:\n";
    std::cout << "1. Decimal to Binary\n";
    std::cout << "2. Binary to Decimal\n";
    std::cin >> choice;

    if (choice == 1) {
        unsigned int decimalNumber;
        std::cout << "Enter a decimal number: ";
        std::cin >> decimalNumber;
        std::cout << "Binary representation: " << DecimalToBinary(decimalNumber) << std::endl;
    }
    else if (choice == 2) {
        std::string binaryString;
        std::cout << "Enter a binary number: ";
        std::cin >> binaryString;
        std::cout << "Decimal representation: " << BinaryToDecimal(binaryString) << std::endl;
    } else {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}
