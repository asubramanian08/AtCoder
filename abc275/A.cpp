// Official: Correct
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int n, x, maxHeight, idx = 0;
    cin >> n >> maxHeight;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (maxHeight < x)
        {
            maxHeight = x;
            idx = i;
        }
    }
    cout << (idx + 1) << endl;
}