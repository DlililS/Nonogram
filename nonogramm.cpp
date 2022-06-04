#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
const int n = 5;
unsigned int rand_value = 0;
bool a = true;
int m[n][n];
int check[n][n];
void setcur(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void matrix() {
    int c = 0;
    int z = 0;
    int c1 = 0;
    srand(rand_value);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (c < 4 && c1 < 4) {
                m[i][j] = rand() % 2;
                if (m[i][j] == 1) {
                    c++;
                }
                if (m[j][i] == 1) {
                    c1++;
                }
                z++;

            }
            if (c > 3) {
                m[i][j] = 0;
                c--;
            }
            if (c1 > 3) {
                m[j][i] = 0;
                c1--;
            }
            if (z == 4) {
                if (c < 1) {
                    m[i][j] = 1;
                    c++;
                }
                if (c1 < 1) {
                    m[j][i] = 1;
                    c1++;
                }
            }
        }
        z = 0;
        c1 = 0;
        c = 0;
    }

}
void matrcheck(int a, int b) {
    for (int i = 0; i < n * n; i++) {
        if (a > 0 && a < 6 && b>0 && b < 6)
            if (check[a - 1][b - 1] == 1)
                check[a - 1][b - 1] = 0;
            else
                check[a - 1][b - 1] = 1;
    }
}
void edge(int a, int b) {
    int s = 0;
    int k = 0;
    int z = 0;
    int c1 = 0;
    int c = 0;
    int a1 = a;
    int b1 = b;
    int mas1[n];
    int mas2[n];
    int mas3[n];
    cout << "Enter the column number and row number." << endl;
    cout << "If you want to end the game, press any key and press the space bar." << endl << endl;
    cout << "  12345" << endl;
    matrcheck(a1, b1);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ';
        for (int j = 0; j < n; j++)
        {
            cout << check[i][j];
            if (m[i][j] == 1)
                s++;
            if (s > 0 && m[i][j] == 0) {
                if (z == 0) {
                    k = s;
                    z++;
                }
            }
            if (k > 0 && m[i][j] == 1 && j > 0) {
                c++;
            }
            if (c > 0 && m[i][j] == 0 && j < 4 && m[i][j + 1] == 1) {
                c1 = 1;
                c = 1;
            }
        }
        if (k > 0)
            cout << ' ' << k;
        else
            cout << ' ' << s;
        if (c > 0) {
            if (c1 > 0) {
                cout << ' ' << c1 << ' ' << c1 << endl;
            }
            else
                cout << ' ' << c << endl;
        }
        else
            cout << endl;
        s = 0;
        c = 0;
        k = 0;
        z = 0;
        c1 = 0;
    }
    cout << endl;
    s = 0;
    c = 0;
    k = 0;
    z = 0;
    c1 = 0;
    int z1 = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++)
        {
            if (m[i][j] == 1) {
                s++;
            }
            if (s > 0 && m[i][j] == 0) {
                if (z == 0) {
                    k = s;
                    z++;
                }
            }
            if (k > 0 && m[i][j] == 1) {
                c++;
            }
            if (c > 0 && m[i][j] == 0 && j < 4 && m[i][j + 1] == 1) {
                c1 = 1;
                c = 1;
            }
        }
        if (c > 0) {
            mas1[j] = k;
            if (c > 0) {
                if (c1 > 0) {
                    mas2[j] = c1;
                    mas3[j] = c1;
                }
                else {
                    mas2[j] = c;
                    mas3[j] = 0;
                }
            }
        }
        else {
            mas1[j] = s;
            mas2[j] = 0;
            mas3[j] = 0;
        }
        s = 0;
        c = 0;
        k = 0;
        z = 0;
        c1 = 0;
    }
    s = 0;
    c = 0;
    k = 0;
    z = 0;
    c1 = 0;
    cout << ' ' << ' ';
    for (int i = 0; i < n; i++) {

        if (mas1[i] == 0) {
            cout << ' ';
        }
        else
            cout << mas1[i];
    }
    cout << endl << ' ' << ' ';
    for (int i = 0; i < n; i++) {

        if (mas2[i] == 0) {
            cout << ' ';
        }
        else
            cout << mas2[i];
    }
    cout << endl << ' ' << ' ';
    for (int i = 0; i < n; i++) {
        if (mas3[i] == 0) {
            cout << ' ';
        }
        else
            cout << mas3[i];
    }
}
bool Check() {
    int c = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (m[i][j] == check[i][j])
                c++;
        }
    }
    if (c == 25)
        return false;
    return true;
}
int main()
{
    int i;
    int j;
    do {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                check[i][j] = 0;
            }
        }
        setcur(0, 0);
        matrix();
        edge(0, 0);
        do {
            setcur(0, 0);
            i = _getch();
            if (i == 49) i = 1;
            if (i == 50) i = 2;
            if (i == 51) i = 3;
            if (i == 52) i = 4;
            if (i == 53) i = 5;
            if (i == 32) {
                break;
            }
            j = _getch();
            if (j == 49) j = 1;
            if (j == 50) j = 2;
            if (j == 51) j = 3;
            if (j == 52) j = 4;
            if (j == 53) j = 5;
            if (j == 32) {
                break;
            }
            edge(i, j);
            Sleep(100);
        } while (Check());
        rand_value++;
    } while (j != 32 && i != 32);
    edge(0, 0);
    cout << endl << "Game over";
}