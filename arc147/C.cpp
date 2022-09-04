// Official: Wrong answer
#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<long long, long long>;
using pib = pair<long long, bool>;
#define MOD 5223372036854775807

int main(void)
{
    long long n, curr = 0, rem = 0;
    cin >> n;
    pii *arr = new pii[n];
    pib *endPoints = new pib[2 * n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        endPoints[i * 2 + 0] = pii(arr[i].first, false);
        endPoints[i * 2 + 1] = pib(arr[i].second, true);
    }
    sort(endPoints, endPoints + n * 2);
    sort(arr, arr + n);
    for (long long i = 1; i < n; i++)
    {
        rem = (rem + (i * (arr[i].first - arr[i - 1].first)) % MOD) % MOD;
        curr = (curr + rem) % MOD;
    }
    long long left = 0, middle = 1, right = n - 1, ans = curr;
    for (long long i = 1; i < 2 * n; i++)
    {
        curr += (((left - right + MOD) * (endPoints[i].first - endPoints[i - 1].first)) % MOD * middle) % MOD;
        curr %= MOD;
        ans = min(ans, curr);

        if (endPoints[i].second == false)
            right--, middle++;
        else
            left++, middle--;
    }
    cout << ans << endl;
}