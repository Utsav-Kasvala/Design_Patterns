#include <iostream>
#include <string>

using namespace std;

// Interface for the Server
class Server {
public:
    virtual void access() = 0;
    virtual ~Server() {}
};

// Real server that contains the actual logic
class RealServer : public Server {
public:
    void access() override {
        cout << "Access granted to Real Server. Performing operations..." << endl;
    }

    ~RealServer() {
        cout << "RealServer destroyed." << endl;
    }
};

// Proxy class that controls access to the RealServer
class ServerProxy : public Server {
private:
    RealServer* realServer;     // Pointer to the real server
    string role;                // Role of the user (Admin or Client)

public:
    ServerProxy(const string& userRole) : realServer(nullptr), role(userRole) {}

    void access() override {
        if (role == "Admin") {
            cout << "[Proxy] Admin verified. Granting full access." << endl;
            // Lazy instantiation
            if (!realServer) realServer = new RealServer();
            realServer->access();
        } else if (role == "Client") {
            cout << "[Proxy] Client detected. Access denied. Read-only or restricted actions only." << endl;
        } else {
            cout << "[Proxy] Unknown role. Access denied." << endl;
        }
    }

    ~ServerProxy() {
        delete realServer;  // Clean up real server if it was created
        cout << "ServerProxy destroyed." << endl;
    }
};

// ---------- Main function ----------
int main() {
    // Admin access
    Server* adminProxy = new ServerProxy("Admin");
    adminProxy->access();
    delete adminProxy;

    cout << endl;

    // Client access
    Server* clientProxy = new ServerProxy("Client");
    clientProxy->access();
    delete clientProxy;

    return 0;
}
