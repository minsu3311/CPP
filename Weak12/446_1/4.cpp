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

// 오류 발생 error: 'int Point::x' is private within this context
// 오류 발생 error: 'int Point::y' is private within this context
// 발생 원인 point 클래스가 protected에서 private로 바뀌며 상속을 할수 없게 되었기 때문에 오류가 발생한다