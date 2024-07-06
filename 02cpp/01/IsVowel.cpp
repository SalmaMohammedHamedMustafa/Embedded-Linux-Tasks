#include <cctype>
#include <iostream>

bool isVowel(char ch) {
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int main() {
    char letter;
    std::cout << "Enter a letter: ";
    std::cin >> letter;

    if (!isalpha(letter)) {
        std::cout << "Error: Please enter a valid letter." << std::endl;
    } else {
        if (isVowel(letter)) {
            std::cout << letter << " is a vowel.\n";
        } else {
            std::cout << letter << " is not a vowel.\n";
        }
    }

    return 0;
}
