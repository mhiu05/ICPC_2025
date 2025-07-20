#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
#define all(x) x.begin(), x.end()
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
int a[1000006];
set<int> se;
void snt() {
    for(int i = 2; i <= MAXN; i++) a[i] = 1;
    a[0] = a[1] = 0;
    for(int i = 2; i <= sqrt(MAXN); i++) {
        if(a[i]) {
            for(int j = i * 2; j <= MAXN; j += i) {
                a[j] = 0;
            }
        }
    }
    for(int i = 2; i <= MAXN; i++) {
        if(a[i] == 1) se.insert(i);
    }
}

signed main(){
    faster;
    snt();
    string s;

    while(true) {
        cin >> s;
        if(s == "0") return 0;
        ll ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') continue;
            for(int j = i + 1; j < s.size(); j++) {
                if(j - i > 5) break;
                string s1 = s.substr(i, j - i);
                ll num = stoi(s1);
                auto check = se.find(num);
                if(check != se.end()) ans = max(ans, num);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}