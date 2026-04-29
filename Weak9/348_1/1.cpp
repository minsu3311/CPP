// ================================
// 1번 문제
// MyTime 클래스 생성자 추가
// (매개변수 사용 + 초기화 리스트 사용 안함)
// ================================
#include <iostream>
using namespace std;

class MyTime {
private:
    int hour, min, sec, msec;

public:
    // 기본 생성자
    MyTime() {
        hour = 0;
        min = 0;
        sec = 0;
        msec = 0;
    }

    // 매개변수 생성자
    MyTime(int h, int m, int s, int ms) {
        hour = h;
        min = m;
        sec = s;
        msec = ms;
    }

    void print() {
        cout << hour << ":" << min << ":" << sec << ":" << msec << endl;
    }
};

int main() {
    MyTime t1;
    MyTime t2(10, 20, 30, 400);

    t1.print();
    t2.print();

    return 0;
}