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

ll C[61][61];
void combination(){
    FOR(i, 0, 60){
        FOR(j, 0, i){
            if(i == j || j == 0) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

string solve(int a, int b, int k){
    if(a == 0) return string(b, 'b');
    if(b == 0) return string(a, 'a');
    
    if(k <= C[a + b - 1][a - 1]){
        return "a" + solve(a - 1, b, k);  
    }
    else{
        return "b" + solve(a, b - 1, k - C[a + b - 1][a - 1]);
    }
}

signed main(){
    faster;
    combination();

    int a, b, k; cin >> a >> b >> k;
    cout << solve(a, b, k);

    return 0;
}