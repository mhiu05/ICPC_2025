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

int n, X[10], ok = 1;

void brute_force()
{
    int i = n;
    while (i > 0 && X[i] == 1)
    {
        X[i] = 0;
        --i;
    }
    if (i == 0)
        ok = 0;
    else
    {
        X[i] = 1;
    }
}

void print()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << X[i];
    }
    cout << endl;
}

void init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        X[i] = 0;
    }
}

int main()
{
    faster();
    init();
    while (ok)
    {
        print();
        brute_force();
    }
    return 0;
}