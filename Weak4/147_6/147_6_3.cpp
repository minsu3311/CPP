#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGugu() {
    int a = rand() % 9 + 1;
    int b = rand() % 9 + 1;
    int answer;

    cout << a << " x " << b << " = ";
    cin >> answer;

    if (answer == a * b)
        cout << "정답!\n";
    else
        cout << "오답! 정답은 " << a * b << endl;
}

void playTwoDigitMultiply() {
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;
    int answer;

    cout << a << " x " << b << " = ";
    cin >> answer;

    if (answer == a * b)
        cout << "정답!\n";
    else
        cout << "오답! 정답은 " << a * b << endl;
}

void playAddition(int n) {
    int min = 1;
    for (int i = 1; i < n; i++) min *= 10;
    int max = min * 10 - 1;

    int a = rand() % (max - min + 1) + min;
    int b = rand() % (max - min + 1) + min;
    int answer;

    cout << a << " + " << b << " = ";
    cin >> answer;

    if (answer == a + b)
        cout << "정답!\n";
    else
        cout << "오답! 정답은 " << a + b << endl;
}

int main() {
    srand(time(0));

    int choice;
    cout << "게임 선택 (1: 구구단, 2: 두 자리 곱셈, 3~9: n자리 덧셈): ";
    cin >> choice;

    if (choice == 1) {
        playGugu();
    } else if (choice == 2) {
        playTwoDigitMultiply();
    } else if (choice >= 3 && choice <= 9) {
        playAddition(choice);
    } else {
        cout << "잘못된 선택입니다.\n";
    }

    return 0;
}