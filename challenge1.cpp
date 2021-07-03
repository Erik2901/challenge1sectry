#include <iostream>
#include <conio.h>
using namespace std;

int a=0;
char map[25][25];
char s[1];
short int r;
short int szc;
short int l = 1;
char sy;
short int x = 1;
short int y = 1;
char b = ' ';
void mapsize() {
    cout << "Select map size 1:15x15, 2:20x20, 3:25x25 and press Enter ";
    cin >> s;
    while (true) {
        if (s[0] == '1' || s[0] == '2' || s[0] == '3')
        {
            break;
        }
        else 
        {
            cout << "You select wrong size, Select map size 1:15x15, 2:20x20, 3:25x25 and press Enter ";
            cin >> s;
        }
    }
    if (s[0] == '1') {
        a = 15;
        r = 6;
        szc = 3;
    }
    else if (s[0] == '2') {
        a = 20;
        r = 5;
        szc = 4;
    }
    else if (s[0] == '3') {
        a = 25;
        r = 4;
        szc = 4;
    }
}

void wall() {
    for (int i = 0; i < a; i++) {
        map[0][i] = '#';
    }
    for (int i = 0; i < a; i++) {
        map[a-1][i] = '#';
    }
    for (int i = 0; i < a; i++) {
        map[i][0] = '#';
    }
    for (int i = 0; i < a; i++) {
        map[i][a-1] = '#';
    }
}
void mapout() {
    cout << "Level: " << l << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
void clear() {
    for (int i = 1; i < szc; i++) {
        for (int j = 1; j < szc; j++) {
            map[i][j] = ' ';
        }
    }
    for (int i = a-(szc+1); i < a-1; i++) {
        for (int j = a-(szc+1); j < a-1; j++) {
            map[i][j] = ' ';
        }
    }
    map[a - 2][a - 2] = '!';
}
void raandmap() {
    wall();
    for (int i = 1; i < a-1; i++) {
        for (int j = 1; j < a-1; j++) {
            int a = rand() % r;
            if (a != 1) {
                map[i][j] = ' ';
            }
            else {
                map[i][j] = '#';
            }
        }
    }
    clear();
    map[1][1] = b;
}
void dbutton() {
    if (sy == 'D' || sy == 'd')
    {
        system("cls");
        if (x != a - 1 && map[y][x + 1] != '#')
        {
            x++;
            map[y][x - 1] = ' ';
            map[y][x] = b;
        }
        mapout();
    }
}
void abutton() {
        if (sy == 'A' || sy == 'a')
        {
        system("cls");
        if (x != 0 && map[y][x - 1] != '#')
        {
            x--;
            map[y][x + 1] = ' ';
            map[y][x] = b;
        }
        mapout();
        }
}
void sbutton() {
        if (sy == 'S' || sy == 's')
        {
        system("cls");
        if (y != a - 1 && map[y + 1][x] != '#')
        {
            y++;
            map[y - 1][x] = ' ';
            map[y][x] = b;
        }
        mapout();
        }
}
void wbutton() {
        if (sy == 'W' || sy == 'w')
        {
        system("cls");
        if (y != 0 && map[y - 1][x] != '#')
        {
            y--;
            map[y + 1][x] = ' ';
            map[y][x] = b;
        }
        mapout();
        }
}
void levelup() {
    if (x == a - 2 && y == a - 2)
    {
        system("cls");
        raandmap();
        x = 1;
        y = 1;
        l++;
        map[y][x] = b;
        mapout();
    }
}
void gameplay() {
    while (true)
    {
        sy = _getch();

        dbutton();

        abutton();

        sbutton();

        wbutton();

        levelup();

        if (sy == 'Q' || sy == 'q')
        {
            break;
        }
    }
}
int main(){

    cout << "Select your symbol and press Enter ";
    cin >> b;

    mapsize();

    cout << "You need to take '!' symbol. Use 'W' 'A' 'S' 'D' for moving symbol and press 'Q' for Exit, Press any button for continue " << endl;

    raandmap();

    gameplay();


    system("pause");
    return 0;
}

