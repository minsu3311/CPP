#include "MyTime.h"

int main() {
    MyTime t1, t2, t3;

    t1.read();
    t2.read();

    t3 = t1.add(t2);

    t1.print();
    t2.print();
    t3.print();

    return 0;
}