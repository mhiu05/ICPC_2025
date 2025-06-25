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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            v.push_back(x);
            mp[x]++;
        }
        int check = 0;
        for (auto x : mp)
        {
            if (x.second > 1)
                check = 1;
        }
        if (!check)
            cout << "NO\n";
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (mp[v[i]] > 1)
                {
                    cout << v[i] << endl;
                    break;
                }
            }
        }
    }
    return 0;
}