#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
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

    string s; cin >> s;
    int k; cin >> k;
    s = " " + s;

    int n = s.sz();
    int a[n + 1];
    FOR(i, 1, n) a[i] = i;

    set<string>se;

    do{
        string res = "";
        FOR(i, 1, n){
            res += s[a[i]];
        }
        se.insert(res);
    } while(next_permutation(a + 1, a + n + 1));
    
    int cnt = 0;
    string ans;
    for(string x : se){
        ++cnt;
        if(cnt == k){
            ans = x;
            break;
        }
    }

    FOR(i, 1, ans.sz() - 1) cout << ans[i];

    return 0;
}