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

int n, k, X[20];

void backtrack(int i)
{
    for (int j = X[i - 1] + 1; j <= n - k + i; ++j)
    {
        X[i] = j;
        if (i == k)
        {
            for (int m = 1; m <= k; ++m)
            {
                cout << X[m] << " ";
            }
            cout << endl;
        }
        else
            backtrack(i + 1);
    }
}

int main()
{
    faster();
    cin >> n >> k;
    backtrack(1);
    return 0;
}