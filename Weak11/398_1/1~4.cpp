#include <iostream>
#include <cstring>
using namespace std;

class Sample {
private:
    char* name;

    // (1) 객체 개수 관리용 정적 변수
    static int count;

public:
    // 기본 생성자
    Sample() {
        name = nullptr;
        count++;
    }

    // (2) 생성자 구현
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        count++;
    }

    // (4) 복사 생성자 구현
    Sample(const Sample& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        count++;
    }

    // (3) 소멸자 구현
    ~Sample() {
        delete[] name;
        count--;
    }

    // (1) 객체 개수 출력 함수
    static void printCount() {
        cout << "Sample 객체 수 : " << count << endl;
    }

    void printName() {
        if (name != nullptr)
            cout << "name : " << name << endl;
    }
};

// 정적 변수 초기화
int Sample::count = 0;

int main() {
    Sample::printCount();

    Sample a("sample");
    Sample::printCount();

    Sample b(a);
    Sample::printCount();

    a.printName();
    b.printName();

    return 0;
}