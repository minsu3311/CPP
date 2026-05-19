#include <iostream>
using namespace std;

class Point {
private:   // protected → private 로 변경
    int x, y;

public:
    Point(int xx, int yy) : x(xx), y(yy) { }
};

class Rectangle : public Point {
private:
    int width, height;

public:
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) { }

    void draw() {
        // 오류 발생 부분
        cout << x << "," << y
             << "에 가로 " << width
             << " 세로 " << height
             << "인 사각형을 그려라.\n";
    }
};

int main() {
    Rectangle r(2, 3, 100, 200);

    r.draw();

    return 0;
}