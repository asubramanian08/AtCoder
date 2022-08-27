// Official: Correct
#include <iostream>
using namespace std;
#define MOD 998244353

int main(void)
{
    long long N;
    cin >> N;
    long long x = N % MOD;
    if (x < 0)
        x += MOD;
    cout << x << endl;
    return 0;
}