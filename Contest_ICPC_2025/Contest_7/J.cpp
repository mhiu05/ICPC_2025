#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pf push_front
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

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

signed main(){
    faster;

    int n; cin >> n;
    int a[n], A[n];
    FOR(i, 0, n - 1) {
        cin >> a[i];
        A[i] = a[i];
    }

    int inv = merge_sort(a, 0, n - 1);

    cout << inv << endl;

    FOR(k, 0, n - 2){
        inv = inv - A[k] + (n - A[k] - 1);
        cout << inv << endl;
    }

    return 0;
}