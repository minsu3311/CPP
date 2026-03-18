#include <iostream>

int main() {
    int number;
    std::cout << "정수를 입력하세요 (100000 미만): ";
    std::cin >> number;

    if (number < 0 || number >= 100000) {
        std::cout << "입력값이 범위를 벗어났습니다." << "\n";
        return 1;
    }

    int 만 = number / 10000; 
    int 천 = (number % 10000) / 1000; 
    int 백 = (number % 1000) / 100; 
    int 십 = (number % 100) / 10;
    int 일 = number % 10;

    if (만 > 0)
        std::cout << 만 << "만 ";

    if (천 > 0) 
        std::cout << 천 << "천 ";

    if (백 > 0)
        std::cout << 백 << "백 ";
        
    if (십 > 0) 
        std::cout << 십 << "십 ";

    if (일 > 0) 
        std::cout << 일;

    std::cout << "\n";
    
    return 0;
}