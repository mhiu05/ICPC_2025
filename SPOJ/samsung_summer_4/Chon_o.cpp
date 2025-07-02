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

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

// dp bitmask: https://wiki.vnoi.info/algo/dp/dp-bitmask , https://www.youtube.com/watch?v=rnDh3vdC7WA

ll n, a[5][MAXN];
ll ans = 0, anss = -1e18; // anss là kết quả nếu không chọn ô nào
ll d[17]; // check 2 ô cạnh nhau trong 1 cột
ll dp[17][MAXN];


signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        ans = 0; anss = -1e17;
        cin >> n;
        FOR(i, 1, 4){
            FOR(j, 1, n){
                cin >> a[i][j];
                anss = max(a[i][j], anss);
            }
        }

        // check 2 ô cạnh nhau trong 1 cột
        FOR(i, 0, 15){
            int check = 1;
            FOR(j, 0, 2){
                if(((i >> j) & 1) && ((i >> (j + 1)) & 1)) check = 0;
            }
            d[i] = check;
        }

        FOR(i, 1, n){
            FOR(j, 0, 15){
                dp[j][i] = -1e18;
                if(d[j]){ // nếu 2 ô trong 1 cột ko cạnh nhau
                    ll sum = 0;
                    FOR(x, 0, 3){
                        if((j >> x) & 1) sum += a[x + 1][i]; // tính tổng các ô trong cột hiện tại ko cạnh nhau
                    }
                    FOR(k, 0, 15){
                        if((j & k) == 0 && d[k]){ // Nếu 2 ô cột hiện tại và cột trước ko cạnh nhau và 2 ô trong cột trước ko cạnh nhau
                            dp[j][i] = max(dp[j][i], dp[k][i - 1] + sum);
                        }
                    }
                    ans = max(ans, dp[j][i]);
                }
            }
        }

        if(ans == 0){ // nếu tất cả phần tử a[][] âm
            cout << anss << endl;
        }
        else{
            cout << ans << endl;
        }
    }

    return 0;
}