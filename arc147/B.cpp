// Official: Correct
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
using pii = pair<int, int>;

int n, x, *locOf, *arr;
vector<pii> ans;

void swap(int i, int count)
{
    while (count > 0)
    {
        int diff = min(count, 2);
        int x = arr[i];
        int y = arr[i + diff];
        arr[i] = y;
        arr[i + diff] = x;
        locOf[x] = i + diff;
        locOf[y] = i;
        ans.push_back(pii(i, diff));
        count -= diff;
        i += diff;
    }
};

int main(void)
{
    cin >> n;
    locOf = new int[n];
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x - 1;
        locOf[x - 1] = i;
    }
    vector<int> left, right;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != i % 2)
        {
            if (i % 2 == 0)
                left.push_back(i);
            else
                right.push_back(i);
        }
        while (left.size() > 0 && right.size() > 0)
        {
            int x = left.back();
            int y = right.back();
            left.pop_back();
            right.pop_back();
            swap(min(x, y), abs(y - x));
        }
    }
    for (int i = 0; i < n; i++)
    {
        while (locOf[i] - i > 1)
            swap(locOf[i] - 2, 2);
        assert(locOf[i] == i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << (ans[i].second == 1 ? 'A' : 'B') << ' ' << (ans[i].first + 1) << endl;
    return 0;
}