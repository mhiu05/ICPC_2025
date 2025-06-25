#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

using ll = long long;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

struct matrix
{
    ll a[2][2];
    friend matrix operator*(matrix x, matrix y)
    {
        matrix z;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                z.a[i][j] = 0;
                for (int k = 0; k < 2; ++k)
                {
                    z.a[i][j] += x.a[i][k] * y.a[k][j];
                    z.a[i][j] %= mod;
                }
            }
        }
        return z;
    }
};

matrix binpow(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix X = binpow(a, n / 2);
    if (n % 2 == 0)
        return X * X;
    return X * X * a;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        matrix x;
        x.a[0][0] = 1;
        x.a[0][1] = 1;
        x.a[1][0] = 1;
        x.a[1][1] = 0;
        matrix ans = binpow(x, n);
        cout << ans.a[1][0] << endl;
    }
    return 0;
}