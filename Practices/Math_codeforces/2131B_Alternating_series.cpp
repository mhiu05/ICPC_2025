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
        if(n % 2 == 0){
            FOR(i, 1, n - 2){
                if(i % 2 == 1) cout << -1 << " ";
                else cout << 3 << " ";
            }
            cout << -1 << " " << 2;
        }
        else{
            FOR(i, 1, n){
                if(i % 2 == 1){
                    cout << -1 << " ";
                }
                else cout << 3 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}