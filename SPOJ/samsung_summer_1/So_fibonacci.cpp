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

int main()
{
    faster();
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << F[n] << endl;
    }
    return 0;
}