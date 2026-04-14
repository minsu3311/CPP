#include "MyTime.h"
#include <iomanip>

void MyTime::convert(double duration) {
    int total = (int)(duration * 1000);

    msec = total % 1000;
    total /= 1000;

    sec = total % 60;
    total /= 60;

    min = total % 60;
    total /= 60;

    hour = total;
}

void MyTime::print() {
    cout << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << min << ":"
         << setw(2) << sec << ":"
         << setw(3) << msec << endl;
}

MyTime MyTime::add(MyTime t) {
    MyTime r;

    r.msec = msec + t.msec;
    r.sec = sec + t.sec;
    r.min = min + t.min;
    r.hour = hour + t.hour;

    if (r.msec >= 1000) {
        r.sec += r.msec / 1000;
        r.msec %= 1000;
    }
    if (r.sec >= 60) {
        r.min += r.sec / 60;
        r.sec %= 60;
    }
    if (r.min >= 60) {
        r.hour += r.min / 60;
        r.min %= 60;
    }

    return r;
}

void MyTime::reset() {
    hour = min = sec = msec = 0;
}

void MyTime::read() {
    cout << "시간 입력 (시 분 초 밀리초): ";
    cin >> hour >> min >> sec >> msec;
}