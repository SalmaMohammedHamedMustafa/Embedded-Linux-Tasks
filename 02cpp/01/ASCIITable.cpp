#include <iostream>

int main() {
    std::cout << "+----------+\n";
    std::cout << "ASCII Table\n";
    std::cout << "+----------+\n";
    std::cout << "Char | ASCII\n";
    std::cout << "+----------+\n";

    for (int i = 0; i < 128; ++i) {
        std::cout <<"|  "<< (char)i <<  "  |  " << i <<"  |"<<  '\n';
    }

    return 0;
}
