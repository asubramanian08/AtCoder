// Official: Correct
#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    int n, x, ans = 0;
    multiset<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.insert(x);
    }
    while (a.size() > 1)
    {
        int x = *a.begin();
        int y = *a.rbegin();
        a.erase(a.find(y));
        if (y % x)
            a.insert(y % x);
        ans++;
    }
    cout << ans << endl;
    return 0;
}