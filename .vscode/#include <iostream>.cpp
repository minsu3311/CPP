#include <iostream>

int main() {
    int n;
    std::cin >> n;

    double s = 0.0;
    double pm = 1.0;

    for (int i = 0; i <= n; ++i) {
        s += pm * (1.0 / (2 * i + 1));
        pm *= -1.0;
    }

    double pi = 4.0 * s;

    std::cout << "pi = " << pi << std::endl;

    return 0;
}