// Official: Correct
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a[200'010], ct[200'010] = {1};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int prev = 0, distinct = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            distinct++, prev = i;
        ct[distinct]++;
    }
    for (int i = 0; i < n; i++)
        cout << ct[i] << endl;
    return 0;
}