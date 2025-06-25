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

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

// dp markov: Quy hoạch động tính kỳ vọng
// không hiểu công thức

double dp[101][101][101];

int main(){
    faster;

    int A, B, C;
    cin >> A >> B >> C;

    FOD(i, 99, 0){
        FOD(j, 99, 0){
            FOD(k, 99, 0){
                int T = i + j + k;
                dp[i][j][k] = (T + i * dp[i+1][j][k] + j * dp[i][j+1][k] + k * dp[i][j][k+1]) / T;
            }
        }
    }

    cout << fixed << setprecision(6) << dp[A][B][C] << "\n";
    return 0;
}
