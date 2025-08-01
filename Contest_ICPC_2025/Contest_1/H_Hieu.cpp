#include <bits/stdc++.h>
#define ll long long
#define int long long
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

int solve(int a, int b){
    int n = 0;
    while(1){
        int x = n * (n + 1) / 2 + a + b;
        if(x % 2 == 0 && x >= 2*max(a, b)) return n;
        ++n;
    }
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }

    return 0;
}