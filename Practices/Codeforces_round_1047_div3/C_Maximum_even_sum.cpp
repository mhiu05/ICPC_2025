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

void solve(int a, int b){
    int x = a * b + 1;
    if(x % 2 == 0){
        cout << x << endl;
    }
    else if(b % 2 == 0){
        int y = a * b / 2 + 2;
        if(y % 2 == 0){
            cout << y << endl;
        }
        else cout << -1 << endl;
    }
    else {
        cout << -1 << endl;
    }
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        solve(a, b);
    }

    return 0;
}   