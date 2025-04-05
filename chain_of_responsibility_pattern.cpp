#include <iostream>
#include <string>

using namespace std;

// Define log levels as constants
enum LogLevel {
    INFO,
    DEBUG,
    ERROR
};

// Abstract base class for all log handlers
class Logger {
protected:
    Logger* nextLogger;     // Pointer to the next logger in the chain
    LogLevel level;         // Log level handled by this logger

public:
    Logger(LogLevel level, Logger* nextLogger = nullptr)
        : level(level), nextLogger(nextLogger) {}

    // Handles the log request, or passes it to the next handler
    void logMessage(LogLevel msgLevel, const string& message) {
        if (msgLevel == level)
            write(message);

        if (nextLogger)
            nextLogger->logMessage(msgLevel, message);
    }

    // Pure virtual function that each derived logger must implement
    virtual void write(const string& message) = 0;

    virtual ~Logger() {}
};

// Concrete logger for INFO level
class InfoLogger : public Logger {
public:
    InfoLogger(Logger* nextLogger = nullptr)
        : Logger(INFO, nextLogger) {}

    void write(const string& message) override {
        cout << "[INFO]: " << message << endl;
    }

    ~InfoLogger() {
        cout << "InfoLogger destroyed" << endl;
    }
};

// Concrete logger for DEBUG level
class DebugLogger : public Logger {
public:
    DebugLogger(Logger* nextLogger = nullptr)
        : Logger(DEBUG, nextLogger) {}

    void write(const string& message) override {
        cout << "[DEBUG]: " << message << endl;
    }

    ~DebugLogger() {
        cout << "DebugLogger destroyed" << endl;
    }
};

// Concrete logger for ERROR level
class ErrorLogger : public Logger {
public:
    ErrorLogger(Logger* nextLogger = nullptr)
        : Logger(ERROR, nextLogger) {}

    void write(const string& message) override {
        cout << "[ERROR]: " << message << endl;
    }

    ~ErrorLogger() {
        cout << "ErrorLogger destroyed" << endl;
    }
};

int main() {
    // Build the logger chain: ERROR -> DEBUG -> INFO
    Logger* loggerChain = new ErrorLogger(
                            new DebugLogger(
                                new InfoLogger(nullptr)));

    // Log messages of different levels
    loggerChain->logMessage(INFO, "This is an information message.");
    loggerChain->logMessage(DEBUG, "This is a debug message.");
    loggerChain->logMessage(ERROR, "This is an error message.");

    // Cleanup (manual deletion since we used raw pointers)
    delete loggerChain;  // Only deletes the first one

    // NOTE: To delete the full chain properly, you'd loop through and delete each,
    // or better, use smart pointers (want me to refactor it to use `unique_ptr`?)

    return 0;
}
