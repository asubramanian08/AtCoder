// Official: 14/24
#include <iostream>
using namespace std;

int main(void)
{
    long long n, a, b;
    cin >> n >> a >> b;
    if (a <= b)
    {
        cout << n;
        return 0;
    }
    n -= a - 1;
    long long ct = n / a;
    long long rem = n % a;
    long long ans = min(rem, b) + (ct * b);
    cout << ans << endl;
    return 0;
}