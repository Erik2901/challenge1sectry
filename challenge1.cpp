#include <iostream>
#include <conio.h>
using namespace std;


char map[25][25];
void mapout() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
void clear() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            map[i][j] = ' ';
        }
    }
    for (int i = 22; i < 25; i++) {
        for (int j = 22; j < 25; j++) {
            map[i][j] = ' ';
        }
    }
}
void raandmap() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            int a = rand() % 4;
            if (a != 1) {
                map[i][j] = ' ';
            }
            else {
                map[i][j] = '#';
            }
        }
    }
    clear();
    map[24][24] = '!';
}




int main()
{

   /* for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = '#';
        }
        
    }*/
    /*for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }*/
    
    cout << "Select your symbol and press Enter ";
    char sy;
    int x = 0;
    int y = 0;
    char b = ' ';
    cin >> b;
    cout << "You need to take '!' symbol. Use 'W' 'A' 'S' 'D' for moving symbol and press 'Q' for Exit " << endl;
    raandmap();
    map[0][0] = b;
    while (true)
    {
        sy = _getch();
        if (sy == 'D' || sy == 'd')
        {
           system("cls");
           if (x !=24 && map[y][x+1] != '#')
           {
               x++;
               map[y][x - 1] = ' ';
               map[y][x] = b;
           }
           mapout();
        }
        else if (sy == 'A' || sy == 'a')
        {
            system("cls");
            if (x != 0 && map[y][x-1] != '#')
            {
                x--;
                map[y][x + 1] = ' ';
                map[y][x] = b;
            }
            mapout();
        }
        else if (sy == 'S' || sy == 's')
        {
            system("cls");
            if (y != 24 && map[y+1][x] != '#')
            {
                y++;
                map[y - 1][x] = ' ';
                map[y][x] = b;
            }
            mapout();
        }
        else if (sy == 'W' || sy == 'w')
        {
            system("cls");
            if (y != 0 && map[y-1][x] != '#')
            {
                y--;
                map[y + 1][x] = ' ';
                map[y][x] = b;
            }
            mapout();
        }
        else if (sy == 'Q' || sy == 'q')
        {
            break;
        }
        if (x == 24 && y == 24)
        {
            system("cls");
            raandmap();
            x = 0;
            y = 0;
            map[y][x] = b;
            mapout();
        }
    }





    system("pause");
    return 0;
}

