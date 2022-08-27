// Official: Incorrect
#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> cycle;
int stopAt;
bool vis[200010] = {0}, cont = true;
bool DFS(int nd, int par, vector<int> *graph)
{
    if (vis[nd])
    {
        stopAt = nd;
        cont = false;
        return true;
    }
    vis[nd] = true;
    for (int next : graph[nd])
        if (next != par)
        {
            bool ret = DFS(next, nd, graph);
            if (ret)
            {
                cycle.insert(nd);
                return stopAt != nd;
            }
            if (cont == false)
                return false;
        }
    return false;
}

int main(void)
{
    long long n, a, b, q;
    cin >> n;
    vector<int> *graph = new vector<int>[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(0, -1, graph);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--, b--;
        bool works = (cycle.find(a) != cycle.end() || cycle.find(b) != cycle.end());
        cout << (works ? "Yes" : "No") << endl;
    }
    return 0;
}