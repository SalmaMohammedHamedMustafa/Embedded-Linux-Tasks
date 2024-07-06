#include <iostream>
#include <string>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    // Convert the integer to a string
    std::string numStr = std::to_string(num);

    // Initialize sum
    int sum = 0;

    // Calculate the sum of digits using string manipulation
    for (char digitChar : numStr) {
        if (digitChar == '-') {
            continue; // Skip the negative sign if present
        }
        int digit = digitChar - '0'; // Convert character to integer
        sum += digit;
    }

    // Output the result
    std::cout << "Sum of digits of " << num << " is: " << sum << std::endl;

    return 0;
}
