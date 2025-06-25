#include <bits/stdc++.h>
#define endl "\n"
#define second sc
#define first fi

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 1;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    faster();
    int n;
    cin >> n;
    int a[n + 1];
    int F[n + 5];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        F[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (a[i] > a[j])
            {
                F[i] = max(F[i], F[j] + 1);
            }
        }
    }
    cout << *max_element(F + 1, F + n + 1);
    return 0;
}