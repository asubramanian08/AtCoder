// Official: Incorrect
#include <iostream>
using namespace std;

int main(void)
{
    long long n, m;
    cin >> n >> m;
    long long total = 0, x = 0;
    for (int i = 0; i < n - 2; i++)
        total += (x += i);
    long long bias = (m - total) / n;
    long long currVal = total + (n * bias);
    long long lastNum = m - currVal;
    lastNum += 5 * n;
    bias += 5;

    x = 0;
    cout << (bias + x) << ' ';
    for (int i = 0; i < n - 2; i++)
    {
        x += i;
        cout << (bias + x) << ' ';
    }
    cout << lastNum << endl;
    return 0;
}