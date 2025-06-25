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

int count(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            if (i % 2 == 0)
                ++cnt;
            if (i * i != n)
                if ((n / i) % 2 == 0)
                    ++cnt;
        }
    }
    return cnt;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}