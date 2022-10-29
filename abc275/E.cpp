// Official: Correct
#include <iostream>
using namespace std;
#define MOD 998244353

long long pow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long half_pow = pow(a, b / 2);
    long long pow_ish = (half_pow * half_pow) % MOD;
    return (pow_ish * (b % 2 ? a : 1)) % MOD;
}
long long inverse(long long p) { return pow(p, MOD - 2); }

int main(void)
{
    ios_base::sync_with_stdio(false);
    long long N, M, K;
    cin >> N >> M >> K;
    long long prob[2][1010] = {{1}};
    int next = 1;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
            prob[next][j] = 0;
        prob[next][N] = prob[1 - next][N];
        for (int j = 0; j < N; j++)
        {
            long long currProb = prob[1 - next][j] * inverse(M) % MOD;
            for (int k = 1; k <= M; k++)
            {
                int pos = j + k;
                if (pos > N)
                    pos -= 2 * (pos - N);
                prob[next][pos] = (prob[next][pos] + currProb) % MOD;
            }
        }
        next = 1 - next;
    }
    cout << prob[1 - next][N] << endl;
}