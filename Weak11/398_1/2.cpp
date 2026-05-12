#include <iostream>
#include <cstring>
using namespace std;

class Sample {
private:
    char* name;

public:
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void printName() {
        cout << "name : " << name << endl;
    }
};

int main() {
    Sample a("sample");
    a.printName();

    return 0;
}