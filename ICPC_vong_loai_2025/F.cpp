#include <bits/stdc++.h>
#define ll long long
//#define int long long
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
const int MAXN = 1e6 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

signed main(){
    faster;
    int t;
    cin >> t;

    vi A;
    for(int i = 0; i <= MAXN; i++) {
        string s = to_string(i);
        string v = s;
        reverse(all(v));
        int cnt = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] != v[j]) cnt++;
        }
        if(cnt <= 2) A.push_back(i);
    }
    
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        int idx1 = lower_bound(all(A), a) - A.begin();
        int idx2 = upper_bound(all(A), b) - A.begin();
        if(idx2 > 1) idx2--;
        cout << idx2 - idx1 + 1 << '\n';
    }
    

    return 0;
}