#include <bits/stdc++.h>
using namespace std;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

using ll = long long;

const int mod = 1e9 + 7;

int n, k, X[100], a[100], check = 0;

void init()
{
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a[i];
        X[i] = a[i];
    }
}

void brute_force()
{
    int i = k;
    while (i > 0 && X[i] == n - k + i)
    {
        --i;
    }
    if (i == 0)
        check = 1;
    else
    {
        X[i]++;
        for (int j = i + 1; j <= k; ++j)
        {
            X[j] = X[j - 1] + 1;
        }
    }
}

int cnt()
{
    int count = 0;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (a[i] == X[j])
                ++count;
        }
    }
    return k - count;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        init();
        brute_force();
        if (check)
            cout << k << endl;
        else
            cout << cnt() << endl;
        check = 0;
    }

    return 0;
}