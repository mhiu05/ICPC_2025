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

void solve(int a, int b, int k){
    if((a <= k && b <= k) || a == b){
        cout << 1 << endl;
        return;
    }

    if(__gcd(a, b) != 1){
        int a1 = a / __gcd(a, b), b1 = b / __gcd(a, b);
        if(a1 <= k && b1 <= k) cout << 1 << endl;
        else cout << 2 << endl;
    }
    else cout << 2 << endl;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int a, b, k; cin >> a >> b >> k;
        solve(a, b, k);
    }

    return 0;
}