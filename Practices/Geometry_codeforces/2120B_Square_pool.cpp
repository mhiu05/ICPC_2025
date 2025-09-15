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

struct Ball{
    int dx, dy, x, y;
};

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        vector<Ball> a;
        FOR(i, 1, n){
            int Dx, Dy, X, Y; cin >> Dx >> Dy >> X >> Y;
            a.pb({Dx, Dy, X, Y});
        }

        vector<Ball> dia1, dia2;
        for(auto it : a){
            if(it.x + it.y - s == 0){
                dia1.pb(it);
            }
            if(it.x - it.y == 0){
                dia2.pb(it);
            }
        }

        // for(auto it : dia2){
        //     cout << it.dx << " " << it.dy << " " << " " << it.x << " " << it.y << endl;
        // }

        int cnt = 0;
        for(auto it : dia1){
            if((it.dx == -1 && it.dy == 1) || (it .dx == 1 && it.dy == -1)) ++cnt;
        }
        for(auto it : dia2){
            if((it.dx == 1 && it.dy == 1) || (it.dx == -1 && it.dy == -1)) ++cnt;
        }   

        cout << cnt << endl;
    }


    return 0;
}