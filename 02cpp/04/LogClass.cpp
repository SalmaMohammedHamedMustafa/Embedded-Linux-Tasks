#include "LogClass.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>

// Constructor
Logger::Logger() : CurrentLevel(0) {}

// Destructor
Logger::~Logger() {}

// Logs a message at a given severity level
void Logger::Log(int level, const std::string& message) {
    if (level >= CurrentLevel) {
        messages.push_back(FormatMessage(level, message));
    }
}

// Logs an informational message
void Logger::Info(const std::string& message) {
    Log(1, message);
}

// Logs a warning message
void Logger::Warn(const std::string& message) {
    Log(2, message);
}

// Logs an error message
void Logger::Error(const std::string& message) {
    Log(3, message);
}

// Dumps all stored messages to the output
void Logger::Dump() {
    for (const auto& msg : messages) {
        std::cout << msg << std::endl;
    }
}

// Clears all stored messages in the log buffer
void Logger::Clear() {
    messages.clear();
}

// Sets the current logging level
void Logger::SetLevel(int level) {
    CurrentLevel = level;
}

// Gets the current logging level
int Logger::GetLevel() {
    return CurrentLevel;
}

// Formats a log message by appending a timestamp and the severity level
std::string Logger::FormatMessage(int level, const std::string& message) {
    std::ostringstream formattedMessage;
    
    // Get current time
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    
    // Format time and log level
    formattedMessage << "[" << std::ctime(&now_time);
    formattedMessage.seekp(-1, formattedMessage.cur); // Remove the newline character added by ctime
    formattedMessage << "] ";

    switch (level) {
        case 1: formattedMessage << "[INFO] "; break;
        case 2: formattedMessage << "[WARN] "; break;
        case 3: formattedMessage << "[ERROR] "; break;
        default: formattedMessage << "[UNKNOWN] "; break;
    }

    // Append the message
    formattedMessage << message;
    
    return formattedMessage.str();
}
