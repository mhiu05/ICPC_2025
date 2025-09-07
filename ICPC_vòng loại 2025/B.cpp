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
set<int> s;
void pttsnt(int n){
    int cnt = 1;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){
            s.insert(i);
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n != 1) s.insert(n);
}

void pttsnt1(int n, set<int> &s1){
    int cnt = 1;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){
            s1.insert(i);
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n != 1) s1.insert(n);
}

signed main(){
    faster;

    int n, m;
    cin >> n >> m;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pttsnt(a[i]);
    }
    int cnt = 0;
    vi ans;
    for(int i = 1; i <= m; i++) {
        set<int> s1;
        pttsnt1(i, s1);
        int check = 0;
        for(int x: s1) {
            if(s.count(x)) {
                check = 1;
                //continue;
                break;
            } 
        }
        if(check) continue;
        ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(int x: ans) cout << x << ' ';
    return 0;
}