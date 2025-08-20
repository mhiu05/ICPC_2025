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

int cntDiv(int n){
    int cnt = 0;
    int can = sqrt(n);
    FOR(i, 1, can){
        if(n % i == 0){
            ++cnt;
            if(i * i != n) ++cnt;
        }
    }
    return cnt;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << cntDiv(n) << endl;
    }

    return 0;
}