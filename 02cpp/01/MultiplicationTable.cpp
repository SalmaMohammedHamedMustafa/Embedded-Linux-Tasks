#include <iostream>
#include <iomanip> //to set the width in printing "setw() manipulator"

int main() {
    int tableSize ;

    std::cout<<"Enter the size of the table: ";
    std::cin>>tableSize; 
    
    std::cout << "Multiplication Table\n";
    std::cout << "------------------------------------------\n";

    std::cout << std::setw(4) << " ";
    for (int i = 1; i <= tableSize; ++i) {
        std::cout << std::setw(4) << i;
    }
    std::cout << std::endl;

    for (int i = 1; i <= tableSize; ++i) {
        std::cout << std::setw(4) << i; 
        for (int j = 1; j <= tableSize; ++j) {
            std::cout << std::setw(4) << i * j;
        }
        std::cout << std::endl;
    }

    return 0;
}
