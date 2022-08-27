// Official: Correct
#include <iostream>
using namespace std;
using pii = pair<int, int>;

int orientation(pii p1, pii p2, pii p3)
{
    return (p2.first - p1.first) * (p3.second - p1.second) -
           (p2.second - p1.second) * (p3.first - p1.first);
}

int main(void)
{
    pii points[4];
    for (int i = 0; i < 4; i++)
        cin >> points[i].first >> points[i].second;
    bool works = true;
    for (int i = 0; i < 4 && works; i++)
        works = orientation(points[(i + 3) % 4], points[i], points[(i + 1) % 4]) > 0;
    cout << (works ? "Yes" : "No") << endl;
    return 0;
}