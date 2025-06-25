#include <bits/stdc++.h>
#define endl "\n"
#define second sc
#define first fi

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 1;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

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

matrix binpow(matrix x, int n)
{
    if (n == 1)
        return x;
    matrix y = binpow(x, n / 2);
    if (n % 2 == 0)
    {
        return y * y;
    }
    else
        return y * y * x;
}

int main()
{
    faster();
    ll n;
    cin >> n;
    matrix x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;
    matrix ans = binpow(x, n);
    cout << ans.a[1][0];
    return 0;
}