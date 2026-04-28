#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }

    // 3. 멤버 함수 (void, 참조 전달)
    void add(Complex& a, Complex& b) {
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }

    // 4. 멤버 함수 (return, 참조 전달)
    Complex add(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // 5. 연산자 오버로딩
    Complex operator+(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};

// 1. 일반 함수 (void, 참조 전달)
void add_ref(Complex& result, Complex& a, Complex& b) {
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
}

// 2. 일반 함수 (return, 값 전달)
Complex add_val(Complex a, Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c;

    cout << "[1] 일반 함수 (void, 참조 전달): ";
    add_ref(c, a, b);
    c.print();  // 4 + 6i

    cout << "[2] 일반 함수 (return, 값 전달): ";
    c = add_val(a, b);
    c.print();

    cout << "[3] 멤버 함수 (void, 참조 전달): ";
    c.add(a, b);
    c.print();

    cout << "[4] 멤버 함수 (return): ";
    c = a.add(b);
    c.print();

    cout << "[5] 연산자 오버로딩: ";
    c = a + b;
    c.print();

    return 0;
}