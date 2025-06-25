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
    int k, x;
    cin >> k >> x;
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    int front = 1, after = x;
    int step = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > after)
        {
            step += a[i] - after;
            after = a[i];
            front = after - x + 1;
        }
        else if (a[i] <= after && a[i] >= front)
            continue;
        else
        {
            step += front - a[i];
            front = a[i];
            after = front + x - 1;
        }
    }
    cout << step;
    return 0;
}