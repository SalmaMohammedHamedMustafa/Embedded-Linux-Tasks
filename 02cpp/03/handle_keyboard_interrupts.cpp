#include <iostream>
#include <csignal>
#include <termios.h>
#include <unistd.h>

// Signal handler for custom signals
void customSignalHandler1(int signum) {
    std::cout << "Custom signal (Ctrl+X) (" << signum << ") received.\n";
    // Additional custom behavior can be added here
}

void customSignalHandler2(int signum) {
    std::cout << "Custom signal (Ctrl+Y) (" << signum << ") received.\n";
    // Additional custom behavior can be added here
}

void customSignalHandler3(int signum) {
    std::cout << "Custom signal (Ctrl+C) (" << signum << ") received.\n";
    // Additional custom behavior can be added here
}

// Function to configure terminal to read single characters
void configureTerminal(struct termios &orig_termios) {
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &orig_termios); // Get current terminal attributes
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios); // Set new terminal attributes
}

// Function to reset terminal to original configuration
void resetTerminal(struct termios &orig_termios) {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios); // Reset terminal attributes
}

int main() {
    struct termios orig_termios;
    configureTerminal(orig_termios);

    // Register the signal handlers for SIGUSR1, SIGUSR2, and SIGINT
    signal(SIGUSR1, customSignalHandler1);
    signal(SIGUSR2, customSignalHandler2);
    signal(SIGINT, customSignalHandler3);

    std::cout << "Press Ctrl+X to trigger custom signal for SIGUSR1.\n";
    std::cout << "Press Ctrl+Y to trigger custom signal for SIGUSR2.\n";
    std::cout << "Press Ctrl+C to trigger custom signal for SIGINT.\n";

    while (true) {
        char ch = getchar();
        if (ch == 24) { // ASCII value for Ctrl+X is 24
            raise(SIGUSR1); // Send the custom signal SIGUSR1 to this process
        }
        if (ch == 25) { // ASCII value for Ctrl+Y is 25
            raise(SIGUSR2); // Send the custom signal SIGUSR2 to this process
        }
    }

    resetTerminal(orig_termios);
    return 0;
}
