#include <iostream>
using namespace std;

class Point {
protected:
    int x, y;

public:
    Point(int xx, int yy) : x(xx), y(yy) { }

    void draw() {
        cout << x << "," << y << "에 점을 그려라.\n";
    }
};

// Rectangle 클래스 정의
class Rectangle : public Point {
private:
    int width, height;
};