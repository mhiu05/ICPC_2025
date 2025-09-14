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
const int BASE = 31;

using namespace std;

void solve(string s, int k){
    int n = s.sz();
    set<int> se;

    FOR(l, 0, n - 1){
        stack<char> st;
        int hash = 0;
        int delta = 0;
        int cur_depth = 0, max_depth = 0;
        FOR(r, l, n - 1){
            hash = (hash * BASE + s[r]) % MOD;
            if(s[r] == '('){
                delta++;
                cur_depth++;
                max_depth = max(max_depth, cur_depth);
            }
            else{
                delta--;
                cur_depth--;
                if(delta < 0) break;
            }
            if(delta == 0){
                if(max_depth == k){
                    se.insert(hash);
                }
            }
        }
    }

    cout << se.sz() << endl;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int k; cin >> k;
        solve(s, k);
    }

    return 0;
}