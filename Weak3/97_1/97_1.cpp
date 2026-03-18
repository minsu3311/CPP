#include<iostream>

int main()
{   
    printf("1번 문제\n");
    for(int i = 1; i <= 5; i++)
    {
      for(int j = 1; j <= i; j++)
        {
            std::cout << j;
        }

        std:: cout << "\n";
    }
        std:: cout << "\n";
        printf("2번 문제\n");
    for(int j = 1; j <= 5; j++)
    {
    for(int i = 5; i >= j; --i)
    {
        std::cout << i;
    }
    std::cout << "\n";
    }
        printf("\n3번 문제\n");

    for(int i = 1; i <= 5; i++) 
    {
        for(int k = 1; k <= 5 - i; k++)
        {
            std::cout << "  "; 
        }
        for(int j = i; j >= 1; j--)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }

<<<<<<< HEAD
=======

>>>>>>> 1064a4d (sms)
            printf("\n4번 문제\n");
    for(int i = 1; i <= 5; i++)
    {
        for(int k = 1; k <= 5 - i; k++)
        {
            std::cout << "  ";
        }

        for(int j = i; j >= 1; j--)
        {
            std::cout << j << " ";
        }

        for(int m = 2; m <= i; m++)
        {
            std::cout << m << " ";
        }
        std::cout << "\n";
    }
}

