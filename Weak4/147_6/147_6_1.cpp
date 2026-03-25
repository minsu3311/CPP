#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// n자리 덧셈 문제
void playAddition(int n) {
    int min = 1;
    for (int i = 1; i < n; i++) {
        min *= 10;
    }
    int max = min * 10 - 1;

    int a = rand() % (max - min + 1) + min;
    int b = rand() % (max - min + 1) + min;

    int answer;
    cout << a << " + " << b << " = ";
    cin >> answer;

    if (answer == a + b)
        cout << "정답!" << endl;
    else
        cout << "오답! 정답은 " << a + b << endl;
}

int main() {
    srand((unsigned int)time(NULL));

    int n;
    cout << "몇 자리 덧셈을 할까요? ";
    cin >> n;

    playAddition(n);

    return 0;
}