#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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

// ai đến được thứ c - i * (m + 1) là win

void solve(int c, int m){
    if(c % (m + 1) == 0){
        cout << "Second\n";
    }
    else cout << "First\n";
}   

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int c, m; cin >> c >> m;
        solve(c, m);
    }

    return 0;
}