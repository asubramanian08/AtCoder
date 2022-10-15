// Official: Correct
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, C, r, c, N, Q, x, y, len, bound;
    cin >> R >> C >> r >> c >> N;
    r--, c--;
    map<int, set<int>> mr, mc;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        x--, y--;
        mr[x].insert(y);
        mc[y].insert(x);
    }
    cin >> Q;
    char dir;
    for (int i = 0; i < Q; i++)
    {
        cin >> dir >> len;
        if (dir == 'D')
        {
            if (mc.find(c) != mc.end() && mc[c].upper_bound(r) != mc[c].end())
                bound = *mc[c].upper_bound(r);
            else
                bound = R;
            r = min(r + len, bound - 1);
        }
        else if (dir == 'U')
        {
            if (mc.find(c) != mc.end() && mc[c].lower_bound(r) != mc[c].begin())
                bound = *prev(mc[c].lower_bound(r));
            else
                bound = -1;
            r = max(r - len, bound + 1);
        }
        else if (dir == 'L')
        {
            if (mr.find(r) != mr.end() && mr[r].lower_bound(c) != mr[r].begin())
                bound = *prev(mr[r].lower_bound(c));
            else
                bound = -1;
            c = max(c - len, bound + 1);
        }
        else // dir == 'R'
        {
            if (mr.find(r) != mr.end() && mr[r].upper_bound(c) != mr[r].end())
                bound = *mr[r].upper_bound(c);
            else
                bound = C;
            c = min(c + len, bound - 1);
        }
        cout << (r + 1) << " " << (c + 1) << endl;
    }
    return 0;
}