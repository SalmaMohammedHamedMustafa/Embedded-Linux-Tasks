#include "String.hpp"
#include <iostream>

int main() {
    char s1[] = "Hello, World!";
    char s2[] = "Goodbye!";
    char s3[] = "New string assignment!";
    char s4[] = "Apple";
    char s5[] = "Banana";
    
    // Creating a String object using the parameterized constructor
    String str1(s1);
    str1.printS(); // Output: Hello, World!

    // Using the copy constructor
    String str2 = str1;
    str2.printS(); // Output: Hello, World!

    // Testing the assignment operator with another String object
    String str3(s2);
    str3.printS(); // Output: Goodbye!
    str3 = str1; // Assigning str1 to str3
    str3.printS(); // Output: Hello, World!

    // Testing the assignment operator with a C-style string
    str3 = s3;
    str3.printS(); // Output: New string assignment!

    // Test the overloaded + operator
    String str4 = str1 + str2; // Concatenates str1 and str2
    str4.printS(); // Output: Hello, World!Hello, World!

    str4 = str4 + s3;
    str4.printS(); // Output: Hello, World!Hello, World!New string assignment!

    // Test comparison operators
    bool result = (str1 == str2);
    std::cout << "str1 == str2: " << result << "\n"; // Output: 1 (true)

    result = (str1 == str4);
    std::cout << "str1 == str4: " << result << "\n"; // Output: 0 (false)

    result = (str1 != str4);
    std::cout << "str1 != str4: " << result << "\n"; // Output: 1 (true)

    result = (str1 == s1);
    std::cout << "str1 == s1: " << result << "\n"; // Output: 1 (true)

    // Test <, >, <=, >= operators
    String str5(s4);
    String str6(s5);

    std::cout << "str5 < str6: " << (str5 < str6) << "\n"; // Output: 1 (true)
    std::cout << "str5 > str6: " << (str5 > str6) << "\n"; // Output: 0 (false)
    std::cout << "str5 <= str6: " << (str5 <= str6) << "\n"; // Output: 1 (true)
    std::cout << "str5 >= str6: " << (str5 >= str6) << "\n"; // Output: 0 (false)

    // Test += operator
    str1 += str2; // Concatenate str2 to str1
    str1.printS(); // Output: Hello, World!Hello, World!

    return 0;
}