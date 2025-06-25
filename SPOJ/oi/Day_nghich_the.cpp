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

int merge(int a[], int l, int m, int r)
{
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    int cnt = 0;
    int tmp = l;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[tmp] = x[i];
            ++i;
            ++tmp;
        }
        else
        {
            cnt += x.size() - i;
            a[tmp] = y[j];
            ++tmp;
            ++j;
        }
    }
    while (i < x.size())
    {
        a[tmp] = x[i];
        ++i;
        ++tmp;
    }
    while (j < y.size())
    {
        a[tmp] = y[j];
        ++tmp;
        ++j;
    }
    return cnt;
}

int merge_sort(int a[], int l, int r)
{
    int dem = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        dem += merge_sort(a, l, m);
        dem += merge_sort(a, m + 1, r);
        dem += merge(a, l, m, r);
    }
    return dem;
}

int main()
{
    faster();
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << merge_sort(a, 0, n - 1);
    return 0;
}