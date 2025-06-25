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
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int F[n + 1];
    F[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] >= a[i - 1])
        {
            F[i] = F[i - 1] + 1;
        }
        else
        {
            F[i] = 1;
        }
    }
    cout << *max_element(F + 1, F + n + 1);
    return 0;
}