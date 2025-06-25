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

ll find_lcm(ll n)
{
    queue<string> q;
    q.push("9");
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        ll ans = stoll(s);
        if (ans % n == 0)
            return ans;
        q.push(s + "0");
        q.push(s + "9");
    }
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
        cout << find_lcm(n) << endl;
    }
    return 0;
}