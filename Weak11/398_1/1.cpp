#include <iostream>
using namespace std;

class Sample {
private:
    static int count;

public:
    Sample() {
        count++;
    }

    ~Sample() {
        count--;
    }

    static void printCount() {
        cout << "객체 수 : " << count << endl;
    }
};

int Sample::count = 0;

int main() {
    Sample::printCount();

    Sample a;
    Sample::printCount();

    Sample b;
    Sample::printCount();

    return 0;
}