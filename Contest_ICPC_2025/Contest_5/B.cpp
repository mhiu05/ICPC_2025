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

void solve(string s){
    int cnt = 0, idx = -1;
    stack<int> st;
    int n = s.sz();
    FOR(i, 0, n - 1){
        if(s[i] == '(') st.push(i);
        else if(s[i] == '*') idx = i;
        else{
            if(!st.empty()){
                int j = st.top();
                st.pop();
                if(j < idx) ++cnt;
            }
        }
    }
    cout << cnt << endl;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        solve(s);
    }

    return 0;
}