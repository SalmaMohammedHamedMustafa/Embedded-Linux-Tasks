#include <string>
#include <vector>
/**
 * @class Logger
 * @brief Handles logging of messages at various severity levels.
 *
 * This class provides methods to log messages at different severity levels
 * such as info, warning, and error. It supports storing these messages in a
 * buffer and offers functionality to dump and clear the log buffer.
 */
class Logger {
public:
    /**
     * @brief Constructor for Logger.
     */
    Logger();

    /**
     * @brief Destructor for Logger.
     */
    ~Logger();

    /**
     * @brief Logs a message at a given severity level.
     * @param level The severity level of the message.
     * @param message The message to log.
     */
    void Log(int level, const std::string& message);

    /**
     * @brief Logs an informational message.
     * @param message The informational message to log.
     */
    void Info(const std::string& message);

    /**
     * @brief Logs a warning message.
     * @param message The warning message to log.
     */
    void Warn(const std::string& message);

    /**
     * @brief Logs an error message.
     * @param message The error message to log.
     */
    void Error(const std::string& message);

    /**
     * @brief Dumps all stored messages to the output.
     */
    void Dump();

    /**
     * @brief Clears all stored messages in the log buffer.
     */
    void Clear();

    /**
     * @brief Sets the current logging level.
     * @param level The logging level to set.
     */
    void SetLevel(int level);

    /**
     * @brief Gets the current logging level.
     * @return The current logging level.
     */
    int GetLevel();

private:
    std::vector<std::string> messages; ///< Storage for log messages.
    int CurrentLevel; ///< Current logging level.

    /**
     * @brief Formats a log message by appending a timestamp and the severity level.
     * @param level The severity level of the message.
     * @param message The message to format.
     * @return The formatted log message.
     */
    std::string FormatMessage(int level, const std::string& message);
};
