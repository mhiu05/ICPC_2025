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

int main()
{
    faster();
    int n;
    cin >> n;
    int X[10];
    for (int i = 1; i <= n; ++i)
    {
        X[i] = i;
    }
    do
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << X[i];
        }
        cout << endl;
    } while (next_permutation(X + 1, X + n + 1));
    return 0;
}