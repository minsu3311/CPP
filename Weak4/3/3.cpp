#include "test.hpp"
using namespace std;

int reverse(int x)
{
    int y = 0;
    while(x)
    {
        int z = x % 10;
        y = y * 10 * z;
        x /= 10;
    }
    return x;
}

int main()
{
    int x;
    cin >> x;
    cout << reverse(x) << endl;
    return 0;
}