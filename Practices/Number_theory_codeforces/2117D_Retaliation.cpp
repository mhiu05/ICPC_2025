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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1];
        FOR(i, 1, n) cin >> a[i];
        int y = (2*a[1] - a[2]) / (n + 1);
        int x = a[2] - a[1] + y;

        if(x < 0 || y < 0){
            cout << "NO\n" << endl;
            continue;
        }

        FOR(i, 1, n){
            a[i] = a[i] - i * x;
            a[i] = a[i] - (n - i + 1) * y; 
        }

        int check = 1;
        FOR(i, 1, n) {
            if(a[i] != 0) check = 0;
        }
        
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
} 