// Official: Correct
#include <iostream>
#include <cassert>
using namespace std;

char board[9][9];
bool contains(double points[4])
{
    int p[4];
    for (int i = 0; i < 4; i++)
        if (points[i] != int(points[i]))
            return false;
        else
            p[i] = int(points[i]);
    for (int i = 0; i < 4; i++)
        if (p[i] < 0 || p[i] >= 9)
            return false;
    if (board[p[0]][p[1]] == '#' &&
        board[p[2]][p[3]] == '#')
        return true;
    else
        return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    int count = 0;
    for (int a = 0; a < 9; a++)
        for (int b = 0; b < 9; b++)
            if (board[a][b] == '#')
                for (int c = 0; c < 9; c++)
                    for (int d = 0; d < 9; d++)
                        if (board[c][d] == '#' && pair(a, b) != pair(c, d))
                        {
                            double p1x = (+a - b + c + d) / 2.0;
                            double p1y = (+a + b - c + d) / 2.0;
                            double p2x = (+a + b + c - d) / 2.0;
                            double p2y = (-a + b + c + d) / 2.0;
                            double arr[4] = {p1x, p1y, p2x, p2y};
                            count += contains(arr);
                        }
    assert(count % 2 == 0);
    cout << (count / 4) << endl;
}