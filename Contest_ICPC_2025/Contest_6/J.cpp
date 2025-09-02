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

// E(a, b, c) = 1 + a/n *  E(a + 1, b, c) + b/n * E(a, b + 1, c) + c / n * E(a, b, c + 1)
// E(100, b, c) = E(a, 100, c) = E(a, b, 100) = 0; a, b, c <= 100

double E[101][101][101];

signed main(){
    faster;

    int a, b, c; cin >> a >> b >> c;


    FOD(i, 99, 0){
        FOD(j, 99, 0){
            FOD(k, 99, 0){
                int n = i + j + k;
                if(n == 0) continue;
                E[i][j][k] = 1.0;
                if(i < 99) E[i][j][k] += (1.0*i/n) * E[i + 1][j][k];
                if(j < 99) E[i][j][k] += (1.0*j/n) * E[i][j + 1][k];
                if(k < 99) E[i][j][k] += (1.0*k/n) * E[i][j][k + 1];
            }
        }
    }

    cout << fixed << setprecision(6) << E[a][b][c];

    return 0;
}