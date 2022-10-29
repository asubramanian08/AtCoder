// Official: Correct
#include <iostream>
using namespace std;
#define MOD 998244353

int main(void)
{
    ios_base::sync_with_stdio(false);
    long long arr[6];
    for (int i = 0; i < 6; i++)
        cin >> arr[i];
    for (int i = 0; i < 6; i++)
        arr[i] %= MOD;
    long long left = 1, right = 1;
    for (int i = 0; i < 3; i++)
        left = (left * arr[i]) % MOD;
    for (int i = 3; i < 6; i++)
        right = (right * arr[i]) % MOD;
    long long ans = (left + MOD - right) % MOD;
    cout << ans << endl;
}