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

int check(vi a, vi b){
    FOR(i, 0, 5) {
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

vi quay1(vi v){
    vi tmp(6);
    tmp[0] = v[3];
    tmp[1] = v[0];
    tmp[2] = v[2];
    tmp[3] = v[4];
    tmp[4] = v[1];
    tmp[5] = v[5];
    return tmp;
}

vi quay2(vi v){
    vi tmp(6);
    tmp[0] = v[0];
    tmp[1] = v[4];
    tmp[2] = v[1];
    tmp[3] = v[3];
    tmp[4] = v[5];
    tmp[5] = v[2];
    return tmp;
}

void solve(vi a, vi b){
    queue<pair<vi, int>> q;
    q.push({a, 0});

    while(!q.empty()){
        vi v = q.front().fi; 
        int cnt = q.front().sc;
        q.pop();
        
        if(check(v, b)){
            cout << cnt << endl;    
            return;
        }

        vi tmp1 = v, tmp2 = v;
        vi v1 = quay1(tmp1), v2 = quay2(tmp2);
        q.push({v2, cnt + 1});
        q.push({v1, cnt + 1});
    }
}

signed main(){
    faster;

    vi a(6), b(6);
    FOR(i, 0, 5) cin >> a[i];
    FOR(i, 0, 5) cin >> b[i];

    solve(a, b);
    return 0;
}