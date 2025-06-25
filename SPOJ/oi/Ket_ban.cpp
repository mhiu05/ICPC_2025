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
    ll n, b;
    cin >> n >> b;
    ll a[n];
    for (ll &x : a)
        cin >> x;
    map<ll, ll> mp;
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        if (mp[b - a[i]])
        {
            ans += mp[b - a[i]];
        }
        mp[a[i]]++;
    }
    cout << ans;
    return 0;
}