#pragma once
#include <iostream>
using namespace std;

class MyTime {
private:
    int hour, min, sec, msec;

public:
    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void reset();
    void read();
};