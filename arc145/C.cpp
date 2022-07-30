// Official: Unattempted
#include <iostream>
using namespace std;
#define MOD 998244353

int main(void)
{
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n; i++)
        ans = (ans * i) % MOD;
    for (int i = n + 1; i <= 2 * n; i++)
        ans = (ans * i) % MOD;
    for (int i = 0; i < n; i++)
        ans = (ans * 2) % MOD;
    cout << ans << endl;
    return 0;
}