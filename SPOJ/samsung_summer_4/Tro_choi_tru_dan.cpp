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

// Nin game & Định lý Sprague - Grundy: https://wiki.vnoi.info/algo/math/game-theory.md

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1], b[n + 1];
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];

        int grundy[MAXN];
        FOR(i, 1, n){
            grundy[i] = a[i] % (b[i] + 1);
        }
        int ok = grundy[1];
        FOR(i, 2, n){
            ok ^= grundy[i];
        }
        if(ok == 0){
            cout << "Second\n";
        }
        else cout << "First\n";
    }

    return 0;
}