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

int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
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
        int a[n];
        for (int &x : a)
            cin >> x;
        cout << a[0] << " ";
        for (int i = 1; i < n; ++i)
        {
            cout << lcm(a[i], a[i - 1]) << " ";
        }
        cout << a[n - 1] << endl;
        ;
    }
    return 0;
}