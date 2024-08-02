#include <iostream>
#include <stack>
#include <string>

class Backtrace {
private:
    std::stack<std::string> callStack; // Stack to hold the names of the functions called

public:
    /* 
    Description: Records the entry into a function by logging it and pushing the name onto the stack.
    @param functionName: The name of the function being entered.
    @return: void
    */
    void enterFunction(const std::string& functionName) {
        callStack.push(functionName); // Push the function name onto the stack
        std::cout << "Enter to [" << functionName << "]\n"; // Print enter message
    }

    /* 
    Description: Records the exit from a function by logging it and popping the name from the stack.
    @return: void
    */
    void exitFunction() {
        std::cout << "Exit From [" << callStack.top() << "]\n" ; // Print exit message
        callStack.pop(); // Remove the function name from the stack as we are exiting the function
    }

    /* 
    Description: Prints the current backtrace, showing all function calls still in the stack.
    @return: void
    */
    void printBacktrace() {
        std::cout << "Backtrace as follows:\n";
        int i = 0;
        std::stack<std::string> tempStack = callStack; // Copy to temp stack to maintain original
        while (!tempStack.empty()) {
            std::cout << i++ << " - " << tempStack.top() << std::endl;
            tempStack.pop();
        }
        std::cout << "Back Trace is Finished\n";
    }
};

/* 
Description: Simulates a function that calls another function as part of a demonstration.
@param bt: Reference to the Backtrace instance for managing call logging.
@return: void
*/
void fun3(Backtrace& bt) {
    bt.enterFunction("fun3");
    bt.printBacktrace();
    bt.exitFunction();
}

/* 
Description: Simulates a function that calls another function, demonstrating nested function calls.
@param bt: Reference to the Backtrace instance for managing call logging.
@return: void
*/
void fun2(Backtrace& bt) {
    bt.enterFunction("fun2");
    fun3(bt);
    bt.exitFunction();
}

/* 
Description: Acts as the top-level function in this simulation, calling other functions.
@param bt: Reference to the Backtrace instance for managing call logging.
@return: void
*/
void fun1(Backtrace& bt) {
    bt.enterFunction("fun1");
    fun2(bt);
    bt.exitFunction();
}

/* 
Description: Main function where program execution starts, sets up the Backtrace and calls other functions.
@return: int (status code)
*/
int main() {
    Backtrace bt;
    bt.enterFunction("main");
    fun1(bt);
    bt.exitFunction();
    return 0;
}
