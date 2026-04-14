#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
private:
    int hour, min, sec, msec;

public:
    void set(int h, int m, int s, int ms) {
        hour = h;
        min = m;
        sec = s;
        msec = ms;
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

    t.set(1, 2, 34, 567);
    t.print();   // 01:02:34:567

    return 0;
}