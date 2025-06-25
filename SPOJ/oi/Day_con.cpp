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
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int &x : a)
        cin >> x;

    map<int, int> mp;
    int start = 0, max_len = 0;

    for (int end = 0; end < n; ++end)
    {
        mp[a[end]]++;
        while (mp.size() > m)
        {
            mp[a[start]]--;
            if (mp[a[start]] == 0)
                mp.erase(a[start]);
            start++;
        }

        max_len = max(max_len, end - start + 1);
    }

    cout << max_len << endl;
    return 0;
}