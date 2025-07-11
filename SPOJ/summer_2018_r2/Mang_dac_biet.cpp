#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
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

using namespace std;

signed main(){
    faster;

    int n; cin >> n;
    int a[2*n + 1];
    FOR(i, 1, 2*n) cin >> a[i];

    int cnt1 = 0, cnt2= 0;
    FOR(i, 1,  2*n){
        // dạng 010101....
        if((i % 2 == 1 && a[i] != 0) || (i % 2 == 0 && a[i] != 1)) ++ cnt1;

        // dạng 101010....
        if((i % 2 == 1 && a[i] != 1) || (i % 2 == 0 && a[i] != 0)) ++cnt2;
    }
    cout << min(cnt1, cnt2) / 2;
    return 0;
}