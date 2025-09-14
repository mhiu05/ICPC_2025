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

using namespace std;

int n;
int a[20][20];
int vs[20];
int ans = 0;

void Try(int idx, int sum){
    if(idx == n){
        ans = max(ans, sum);
        return;
    }

    if(vs[idx]){
        Try(idx + 1, sum);
        return;
    }

    // không chọn cạnh nào từ đỉnh idx
    Try(idx + 1, sum);

    // chọn cạnh (idx, j) từ đỉnh idx
    FOR(j, idx + 1, n){
        if(!vs[j]){
            vs[j] = 1;
            vs[idx] = 1;
            Try(idx + 1, sum + a[idx][j]);
            vs[j] = 0;
            vs[idx] = 0;
        }
    }
}

signed main(){
    faster;

    cin >> n;
    FOR(i, 1, n - 1){
        FOR(j, i + 1, n){
            int x; cin >> x;
            a[i][j] = x;
            a[j][i] = x;
        }
    }

    Try(1, 0);
    
    cout << ans;

    return 0;
}