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

int main()
{
    faster();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    ll ans = 0;

    for (int bit = 0; bit < 32; ++bit)
    {
        ll cnt1 = 0;
        for (int x : a)
        {
            if (x & (1 << bit))
                cnt1++;
        }
        ll cnt0 = n - cnt1;

        ans += (cnt1 * cnt0 * (1ll << bit));
    }

    cout << ans << endl;
    return 0;
}   