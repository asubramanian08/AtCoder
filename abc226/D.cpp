// Official: Correct
#include <iostream>
using namespace std;
using pii = pair<long long, long long>;

int main(void)
{
    pair<pii, long long> snakes[100010];
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> snakes[i].first.first >> snakes[i].first.second >> snakes[i].second;
    pair<long long, pii> take[100011];
    pair<long long, pii> leave[100011];
    pair<long long, pii> starter(0, pii(0, 0));
    take[0] = leave[0] = starter;
    pii takeCord(0, 0), leaveCord(0, 0);
    for (long long i = 0; i < n; i++)
    {
        if (take[i].first > leave[i].first)
            leave[i + 1] = take[i];
        else
            leave[i + 1] = leave[i];
        take[i + 1] = starter;
        for (long long j = max(0ll, i - 3); j <= i; j++)
        {
            if (take[j].first + snakes[i].second > take[i + 1].first &&
                (snakes[i].first.first - take[j].second.first >=
                 abs(snakes[i].first.second - take[j].second.second)))
                take[i + 1].first = take[j].first + snakes[i].second;
            if (leave[j].first + snakes[i].second > take[i + 1].first &&
                (snakes[i].first.first - leave[j].second.first >=
                 abs(snakes[i].first.second - leave[j].second.second)))
                take[i + 1].first = leave[j].first + snakes[i].second;
        }
        if (take[i + 1].first != 0)
            take[i + 1].second = snakes[i].first;
    }
    cout << max(take[n].first, leave[n].first) << endl;
    return 0;
}