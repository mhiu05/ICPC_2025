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

int main()
{
    faster();
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += s / v[i];
        s -= v[i] * (s / v[i]);
    }
    cout << sum;
    return 0;
}