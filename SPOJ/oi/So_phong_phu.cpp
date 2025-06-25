#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 1;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    faster();

    // Tiền xử lý tổng các ước số
    vector<ll> sumDiv(MAXN, 0);
    for (ll i = 1; i < MAXN; ++i)
    {
        for (ll j = i; j < MAXN; j += i)
        {
            sumDiv[j] += i;
        }
    }

    // Đếm số phong phú trong đoạn [L, R]
    ll l, r;
    cin >> l >> r;
    ll cnt = 0;
    for (ll i = l; i <= r; ++i)
    {
        if (sumDiv[i] - i > i) // Tổng các ước trừ chính nó
            ++cnt;
    }
    cout << cnt << endl;

    return 0;
}