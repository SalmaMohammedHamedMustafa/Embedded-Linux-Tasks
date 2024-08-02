#include <iostream> // Include the I/O stream library for input and output operations.

// Definition of function 'f' that returns a reference to an integer.
int &f() {
    static int x = 0; // Declare a static integer 'x'. Static variables retain their value between function calls.
    std::cout << x << std::endl; // Print the current value of 'x' to the standard output.
    return x; // Return a reference to 'x'.
}

// The main function - entry point of the program.
int main() {
    f() = 10; // Calls 'f()', which prints '0' (initial value of 'x'), then assigns '10' to 'x'.
    f() = 0;  // Calls 'f()' again, which now prints '10' (modified value of 'x'), then assigns '0' to 'x'.
}
