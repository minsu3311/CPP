// ================================
// 2번 문제
// double 시간을 받아 멤버 초기화
// 함수 중복 생성자
// ================================
#include <iostream>
using namespace std;

class MyTime {
private:
    int hour, min, sec, msec;

public:
    MyTime() {
        hour = min = sec = msec = 0;
    }

    MyTime(int h, int m, int s, int ms) {
        hour = h;
        min = m;
        sec = s;
        msec = ms;
    }

    // double 초 단위 입력
    MyTime(double duration) {
        int total = (int)(duration * 1000);

        hour = total / 3600000;
        total %= 3600000;

        min = total / 60000;
        total %= 60000;

        sec = total / 1000;
        msec = total % 1000;
    }

    void print() {
        cout << hour << ":" << min << ":" << sec << ":" << msec << endl;
    }
};

int main() {
    MyTime t1(3661.789);
    t1.print();

    return 0;
}