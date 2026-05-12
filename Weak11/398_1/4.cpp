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

    // 복사 생성자
    Sample(const Sample& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    ~Sample() {
        delete[] name;
    }

    void printName() {
        cout << "name : " << name << endl;
    }
};

int main() {
    Sample a("sample");
    Sample b(a);

    a.printName();
    b.printName();

    return 0;
}