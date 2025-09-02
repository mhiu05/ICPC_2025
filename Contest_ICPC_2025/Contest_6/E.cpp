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

int n;
int a[101];

signed main(){
    faster;

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    int cnt = 0;
    FOR(i, 1, n){
        FOR(j, i + 1, n){
            FOR(k, j + 1, n){
                if(a[i] != a[j] && a[j] != a[k] && a[i] != a[k]){
                    if(a[i] + a[j] > a[k] && a[j] + a[k] > a[i] && a[i] + a[k] > a[j]){
                        ++cnt;
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}