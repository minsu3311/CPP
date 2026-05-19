#include <iostream>
using namespace std;

class Point {
protected:
    int x, y;

public:
    Point(int xx, int yy) : x(xx), y(yy) { }
};

class Rectangle : public Point {
private:
    int width, height;

public:
    // 멤버 초기화 리스트 사용
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) { }
};