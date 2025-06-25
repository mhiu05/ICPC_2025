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

ll F[93];

void sieve()
{
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 92; ++i)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
}

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

char find_character(ll n, ll k)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (k <= F[n - 2])
    {
        return find_character(n - 2, k);
    }
    else
        return find_character(n - 1, k - F[n - 2]);
}

int main()
{
    faster();
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << find_character(n, k) << endl;
    }
    return 0;
}