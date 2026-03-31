#include <iostream>
using namespace std;
void checkMap(int map[5][5])
{
     bool same;
     for(int i = 0 ; i < 5; i++)
     {
        same = true;
        for(int j = 0 ; j < 5 ; j++)
        {
            if(map[i][0] != map[i][j])
            {
                same = false;
                break;
            }
        }
        if(same)
            cout << "Row" << i << "is all" << map[i][0] << endl;
     }
     for(int j = 0; j < 5; j++)
     {
        same = true;
        for(int i = 1; i < 5; i++)
        {
            if(map[0][j] != map[i][j])
            {
                same = false;
                break;
            }
        }
        if(same)
            cout << "Column" << j << "is all" << map[0][j] << endl;
     }

     same = true;
     for(int i = 0 ; i < 5 ; i++)
     {
        if(map[0][0] != map[i][i])
        {
            same = false;
            break;
        }
     }
     if(same)
        cout << "main diagonal is all" << map[0][0] << endl;
    
    same = true;
    for(int i = 0; i < 5; i++)
    {
        if(map[0][4] != map[i][4-1])
            same = false;
            break;
    }
    if(same)
        cout << "anti diagonal is all" << map[0][4] << endl;
}