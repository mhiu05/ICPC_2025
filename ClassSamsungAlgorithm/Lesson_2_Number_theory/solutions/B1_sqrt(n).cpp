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

void tsnt(int n, map<int, int> &mp){
    FOR(i, 2, sqrt(n)){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                ++cnt;
                n /= i;
            }
            mp[i] = cnt;
        }
    }
    if(n != 1) mp[n] = 1;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> mp;
        tsnt(n, mp);
        for(auto it : mp){
            cout << it.fi << " " << it.sc << endl;
        }
    }

    return 0;
}