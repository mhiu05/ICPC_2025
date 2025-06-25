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
    string s1, s2;
    cin >> s1 >> s2;
    map<char, ll> mp1, mp2;
    for (char c : s1)
        mp1[c]++;
    for (int i = 97; i <= 122; ++i)
    {
        mp2[(char)i] = 0;
    }
    for (char c : s2)
        mp2[c]++;
    ll ans = 0;
    for (auto it : mp1)
    {
        ans += abs(mp2[it.first] - it.second);
    }
    cout << ans;
    return 0;
}