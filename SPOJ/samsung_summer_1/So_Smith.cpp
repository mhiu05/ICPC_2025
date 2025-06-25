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

ll tcs(ll n)
{
    ll sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

ll tsnt(ll n)
{
    ll sum = 0;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                sum += tcs(i);
                n /= i;
            }
        }
    }
    if (n != 1)
    {
        sum += tcs(n);
    }
    return sum;
}

int main()
{
    faster();
    ll n;
    cin >> n;
    if (tcs(n) == tsnt(n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}