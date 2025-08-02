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

// Đề: Cho n điểm bất kì thuộc Oxy, tìm số cách chọn 3 điểm để tạo thành 1 tam giác

// S = 1 / 2 |vector(AB).vector(AC)| = 1 / 2 |(x2 - x1)(y3 - y1) - (x3 - x1)(y2 - y1)|

signed main(){
    faster;

    int n; cin >> n;
    vector<ii> v(n + 1);
    FOR(i, 1, n){
        int x, y; cin >> x >> y;
        v[i].fi = x;
        v[i].sc = y;
    }

    int cnt = 0;
    FOR(i, 1, n){
        FOR(j, i + 1, n){
            FOR(k, j + 1, n){
                int S = (v[j].fi - v[i].fi) * (v[k].sc - v[i].sc) - (v[k].fi - v[i].fi) * (v[j].sc - v[i].sc);
                if(S == 0) ++cnt;
            }
        }
    }
    cout << n * (n - 1) * (n - 2) / 6 - cnt;
    return 0;
}