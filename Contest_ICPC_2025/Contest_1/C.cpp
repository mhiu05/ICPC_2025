#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
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

// Đề: cho xâu S, tìm độ dài xâu con liên tiếp dài nhất của S có kí tự bắt đầu là 'A', kết thúc là 'Z'

signed main(){
    faster;

    string s; cin >> s;
    vi a, z;
    FOR(i, 0, s.sz() - 1){
        if(s[i] == 'A') a.pb(i);
        if(s[i] == 'Z') z.pb(i);
    }
    if(a.sz() != 0 && z.sz() != 0 && z[z.sz() - 1] - a[0] + 1 > 0){
        cout << z[z.sz() - 1] - a[0] + 1;
    }
    else cout << 0;

    return 0;
}