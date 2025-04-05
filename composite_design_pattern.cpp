#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base component interface
class FileSystemEntity {
public:
    virtual void display(int indent = 0) const = 0;
    virtual ~FileSystemEntity() {}
};

// Leaf node: File
class File : public FileSystemEntity {
private:
    string name;

public:
    File(const string& name) : name(name) {}

    void display(int indent = 0) const override {
        cout << string(indent, ' ') << "- File: " << name << endl;
    }
};

// Composite node: Directory
class Directory : public FileSystemEntity {
private:
    string name;
    vector<FileSystemEntity*> contents;  // Can hold Files or other Directories

public:
    Directory(const string& name) : name(name) {}

    void add(FileSystemEntity* entity) {
        contents.push_back(entity);
    }

    void display(int indent = 0) const override {
        cout << string(indent, ' ') << "+ Directory: " << name << endl;
        for (const auto& entity : contents) {
            entity->display(indent + 4);  // Indent for nesting
        }
    }

    ~Directory() {
        for (auto entity : contents) {
            delete entity;
        }
    }
};

// ---------- Main Function ----------
int main() {
    // Create root directory
    Directory* root = new Directory("root");

    // Add files to root
    root->add(new File("readme.txt"));
    root->add(new File("main.cpp"));

    // Create a sub-directory
    Directory* src = new Directory("src");
    src->add(new File("utils.cpp"));
    src->add(new File("utils.h"));

    // Nested sub-directory
    Directory* include = new Directory("include");
    include->add(new File("config.h"));
    src->add(include);  // src/include

    root->add(src);  // root/src

    // Display full structure
    root->display();

    // Cleanup
    delete root;

    return 0;
}
