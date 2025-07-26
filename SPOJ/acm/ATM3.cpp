#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
#define all(x) x.begin(), x.end()
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
ll n, s;
ll a[100];
using namespace std;

signed main(){
    faster;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
        int cnt = 0, i = 0;
        while(n) {
            cnt += n / a[i];
            n %= a[i];
            i++;
        }
        cout << cnt << '\n';
    }

    return 0;
}