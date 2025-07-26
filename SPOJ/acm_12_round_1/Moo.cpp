#include <bits/stdc++.h>
#define ll long long
// #define int long long
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

ll F[100]; //  độ dài của S_i
void sieve(){
    F[0] = 3;
    FOR(i, 1, 99){
        F[i] = 2*F[i - 1] + i + 3;
    }
}

char solve(ll n, int k){
    if(k == 0){
        if(n == 1) return 'm';
        else return 'o';
    }
    if(n <= F[k - 1]) return solve(n, k - 1);
    else if(n <= F[k - 1] + k + 3){
        if(n == F[k - 1] + 1) return 'm';
        else return 'o';
    }
    else return solve(n - F[k - 1] - k - 3, k - 1);
}


signed main(){
    faster;
    sieve();
    
    int n; cin >> n;

    int k = 0;
    while(F[k] < n) k++; 

    cout << solve(n, k);
    

    return 0;
}