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

// chú ý trường hợp x = 1, k = 2

int snt(int n){
    FOR(i, 2, sqrt(n)){
        if(n % i == 0) return 0;
    }
    return n > 1;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int x, k; cin >> x >> k;

        if(x == 1 && k == 2){
            cout << "YES\n";
            continue;
        }

        if(k >= 2){
            cout << "NO\n";
            continue;
        }

        if(snt(x)) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}