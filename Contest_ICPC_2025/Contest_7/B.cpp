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

signed main(){
    faster;

    int n; cin >> n;
    vi a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());

    int check = 0;
    FOR(i, 2, n){
        if(a[i] == a[i - 1] + 1) continue;
        else {
            check = 1;
            cout << a[i - 1] + 1;
            return 0;
        }
    }

    if(!check){
        cout << a[n] + 1;
    }

    return 0;
}