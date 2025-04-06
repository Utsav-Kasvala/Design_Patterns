#include <iostream>
#include <mutex>
using namespace std;

// Singleton Class
class Logger {
private:
    static Logger* instance;
    static mutex mtx; // for thread-safety

    // Private Constructor
    Logger() {
        cout << "Logger initialized." << endl;
    }

    // Prevent Copying
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    // Static method to access the single instance
    static Logger* getInstance() {
        lock_guard<mutex> lock(mtx); // thread-safe
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const string& message) {
        cout << "[LOG]: " << message << endl;
    }
};

// Define static members
Logger* Logger::instance = nullptr;
mutex Logger::mtx;

// Test
int main() {
    Logger* logger1 = Logger::getInstance();
    logger1->log("App started");

    Logger* logger2 = Logger::getInstance();
    logger2->log("User logged in");

    // Should print the same address
    cout << "Logger1 Address: " << logger1 << endl;
    cout << "Logger2 Address: " << logger2 << endl;

    return 0;
}
