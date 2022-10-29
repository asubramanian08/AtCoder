// Official: Correct
#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;
long long f(long long x)
{
    if (m.find(x) != m.end())
        return m[x];
    return m[x] = f(x / 2) + f(x / 3);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    m[0] = 1;
    cout << f(n) << endl;
}