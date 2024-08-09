#include "String.hpp"

int main() {
    char s1 []= "Hello, World!";
    char s2[] = "Goodbye!";
    char s3[] = "New string assignment!";
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

    return 0;
}