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

const ll MOD = 1e18 + 7;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll module = 1e15 + 7;

int main()
{
    faster();
    ll n, m;
    cin >> n >> m;
    ll a[n + 2][m + 2];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] > a[i - 1][j])
            {
                ans += a[i][j] - a[i - 1][j];
            }
            if (a[i][j] > a[i + 1][j])
            {
                ans += a[i][j] - a[i + 1][j];
            }
            if (a[i][j] > a[i][j - 1])
            {
                ans += a[i][j] - a[i][j - 1];
            }
            if (a[i][j] > a[i][j + 1])
            {
                ans += a[i][j] - a[i][j + 1];
            }
        }
    }
    cout << ans + n * m;
    return 0;
}