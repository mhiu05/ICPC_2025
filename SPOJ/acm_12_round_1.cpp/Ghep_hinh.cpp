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

int scp(int n){
    int can = sqrt(n);
    return can * can == n;
}

signed main(){
    faster;

    int square = 0, max_len_edge = 0;

    int a[4], b[4];
    FOR(i,1, 3){
        cin >> a[i] >> b[i];
        square += a[i] * b[i];
        max_len_edge = max({max_len_edge, a[i], b[i]});
    }

    if(scp(square) && sqrt(square) == max_len_edge) cout << max_len_edge;
    else cout << 0;

    return 0;
}