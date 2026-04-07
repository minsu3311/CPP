#include <iostream>
using namespace std;

struct MyTime {
    int hour;
    int min;
    int sec;
    int msec;
};

// 1️⃣ return 방식
MyTime addTime1(MyTime t1, MyTime t2)
{
    MyTime result;

    result.msec = t1.msec + t2.msec;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min;
    result.hour = t1.hour + t2.hour;

    if(result.msec >= 1000){
        result.sec += result.msec / 1000;
        result.msec %= 1000;
    }

    if(result.sec >= 60){
        result.min += result.sec / 60;
        result.sec %= 60;
    }

    if(result.min >= 60){
        result.hour += result.min / 60;
        result.min %= 60;
    }

    return result;
}

// 2️⃣ reference 방식
void addTime2(MyTime t1, MyTime t2, MyTime& t3)
{
    t3.msec = t1.msec + t2.msec;
    t3.sec = t1.sec + t2.sec;
    t3.min = t1.min + t2.min;
    t3.hour = t1.hour + t2.hour;

    if(t3.msec >= 1000){
        t3.sec += t3.msec / 1000;
        t3.msec %= 1000;
    }

    if(t3.sec >= 60){
        t3.min += t3.sec / 60;
        t3.sec %= 60;
    }

    if(t3.min >= 60){
        t3.hour += t3.min / 60;
        t3.min %= 60;
    }
}

// 3️⃣ pointer 방식
void addTime3(MyTime t1, MyTime t2, MyTime* pt)
{
    pt->msec = t1.msec + t2.msec;
    pt->sec = t1.sec + t2.sec;
    pt->min = t1.min + t2.min;
    pt->hour = t1.hour + t2.hour;

    if(pt->msec >= 1000){
        pt->sec += pt->msec / 1000;
        pt->msec %= 1000;
    }

    if(pt->sec >= 60){
        pt->min += pt->sec / 60;
        pt->sec %= 60;
    }

    if(pt->min >= 60){
        pt->hour += pt->min / 60;
        pt->min %= 60;
    }
}

int main()
{
    MyTime t1 = {1, 20, 30, 500};
    MyTime t2 = {2, 40, 40, 800};
    MyTime result;

    // 1️⃣ return 방식
    result = addTime1(t1, t2);
    cout << "Return 방식: "
         << result.hour << ":" << result.min << ":" << result.sec << ":" << result.msec << endl;

    // 2️⃣ reference 방식
    addTime2(t1, t2, result);
    cout << "Reference 방식: "
         << result.hour << ":" << result.min << ":" << result.sec << ":" << result.msec << endl;

    // 3️⃣ pointer 방식
    addTime3(t1, t2, &result);
    cout << "Pointer 방식: "
         << result.hour << ":" << result.min << ":" << result.sec << ":" << result.msec << endl;

    return 0;
}