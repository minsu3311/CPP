#include <iostream>
#include <iomanip> 


int main() {
    int n;
    std::cout << "정수 n을 입력하세요: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "n은 양의 정수여야 합니다." << "\n";
        return 1;
    }

    double pi = 0.0;
    for (int i = 0; i < n; i++) {
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 0) 
            pi += term;
        else 
            pi -= term;
    }

    pi *= 4;

    std::cout << "근사값으로 계산된 π: " << std::fixed << std::setprecision(10) << pi << "\n";
    
    return 0;
}