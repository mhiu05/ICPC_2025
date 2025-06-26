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

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

// ycbt <=> tìm số nghiệm nguyên không âm của x0 + x1 + ... + x9 = n => số nghiệm là C[n + 10 - 1][n]
// x_i là số lần xuất hiện của số i
// vì  X[1] ≤ X[2] ≤ … ≤ X[n] => với số lần xuất hiện i chỉ có 1 kiểu duy nhất X => không xét các hoán vị, chỉ xét số lần xuất hiện.

ll C[205][205];
void combination(){
    for(int i = 0; i <= 200; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0 || i == j) C[i][j] = 1;
            else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= mod;
            }
        }
    }
}

int main(){
    faster;
    combination();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << C[n + 9][n] << endl;
    }

    return 0;
}