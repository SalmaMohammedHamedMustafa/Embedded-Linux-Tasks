#include "LogClass.hpp"

int main() {
    Logger logger;

    // Set logging level to INFO (1)
    logger.SetLevel(1);

    // Log messages
    logger.Info("This is an informational message.");
    logger.Warn("This is a warning message.");
    logger.Error("This is an error message.");

    // Dump the log
    logger.Dump();

    // Clear the log
    logger.Clear();

    // Log another message
    logger.Info("This is a new informational message after clearing the log.");

    // Dump the log again
    logger.Dump();

    return 0;
}
