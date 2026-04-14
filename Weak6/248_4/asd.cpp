#include <iostream>
using namespace std;

int main() {
    string name;
    string id;

    cout << "이름을 입력하세요: ";
    cin >> name;

    cout << "학번을 입력하세요: ";
    cin >> id;

    cout << "\n<출력>" << endl;
    cout << "이름: " << name << endl;
    cout << "학번: " << id << endl;

    return 0;
}