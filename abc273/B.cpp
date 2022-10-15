// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x, k;
    cin >> x >> k;
    for (int i = 0; i < k; i++)
        x = x / 10 + (x % 10 >= 5);
    for (int i = 0; i < k; i++)
        x *= 10;
    cout << x << endl;
    return 0;
}