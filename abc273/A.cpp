// Official: Correct
#include <iostream>
using namespace std;

int f(int x)
{
    if (x == 0)
        return 1;
    return x * f(x - 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}