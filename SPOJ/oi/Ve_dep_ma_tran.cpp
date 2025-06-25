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

const ll MOD = 1e18 + 7;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll module = 1e15 + 7;

int solve(vector<vector<int>> v, int n)
{
    int max_ans = -1e9;
    vector<vector<int>> main_diagonal(n + 2, vector<int>(n + 2, 0));
    vector<vector<int>> secondary_diagonal(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            main_diagonal[i][j] = main_diagonal[i - 1][j - 1] + v[i][j];
            secondary_diagonal[i][j] = secondary_diagonal[i - 1][j + 1] + v[i][j];
        }
    }
    for (int size = 2; size <= n; ++size)
    {
        for (int i = 1; i <= n - size + 1; ++i)
        {
            for (int j = 1; j <= n - size + 1; ++j)
            {
                int main = main_diagonal[i + size - 1][j + size - 1] - main_diagonal[i - 1][j - 1];
                int secondary = secondary_diagonal[i + size - 1][j] - secondary_diagonal[i - 1][j + size];
                max_ans = max(max_ans, main - secondary);
            }
        }
    }
    return max_ans;
}

int main()
{
    faster();
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else
                cin >> v[i][j];
        }
    }
    cout << solve(v, n);
    return 0;
}