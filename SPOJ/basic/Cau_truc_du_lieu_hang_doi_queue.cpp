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
    queue<int> q;
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << q.size() << endl;
        }
        else if (x == 2)
        {
            if (q.empty())
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (x == 3)
        {
            int k;
            cin >> k;
            q.push(k);
        }
        else if (x == 4)
        {
            if (!q.empty())
            {
                q.pop();
            }
        }
        else if (x == 5)
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
            }
            else
                cout << -1 << endl;
        }
        else
        {
            if (!q.empty())
            {
                cout << q.back() << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}   