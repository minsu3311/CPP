#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playTwoDigitMultiply() {
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;

    int answer;
    cout << a << " x " << b << " = ";
    cin >> answer;

    if (answer == a * b)
        cout << "정답!" << endl;
    else
        cout << "오답! 정답은 " << a * b << endl;
}

int main() {
    srand((unsigned int)time(NULL));

    playTwoDigitMultiply();

    return 0;
}