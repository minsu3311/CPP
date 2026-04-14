#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
private:
    int hour, min, sec, msec;

public:
    void read() {
        cout << "시간 입력 (시 분 초 밀리초): ";
        cin >> hour >> min >> sec >> msec;
    }

    void print() {
        cout << setfill('0')
             << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << ":"
             << setw(3) << msec << endl;
    }
};

int main() {
    MyTime t;

    t.read();
    t.print();

    return 0;
}