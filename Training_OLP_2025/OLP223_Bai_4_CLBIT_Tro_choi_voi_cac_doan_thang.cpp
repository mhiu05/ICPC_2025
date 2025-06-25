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

// Nin game & Định lý Sprague - Grundy: https://wiki.vnoi.info/algo/math/game-theory.md
// N: tập các trạng thái x thuộc S: x là trạng thái ban đầu, người chơi đầu luôn thắng
// P: tập các trạng thái x thuộc S: x là trạng thái ban đầu, người chơi sau luôn thắng
// Q: Tập các bước đi hợp lệ
// Định lý Sprague - Grundy:
///// Định lý 1: trạng thái u thuộc p <=> Sprague - Grundy g(u) = 0, g(x) = mex(g(y):(x,y) thuộc Q)
// mex trả về số nguyên không âm nhỏ nhất không nằm trong tập hợp. VD: mex({0,2,3}) = 1
//// Định lý 2: g(x1, x2,...., xn) = g1(x1) XOR.... XOR gn(xn)

int grundy[105][105];
void preGrundy(vector<ii> v){
    for(int len = 1; len <= 100; ++len){
        for(int l = 1; l + len - 1 <= 100; ++l){
            int r = l + len - 1;
            set<int> se;
            for(auto it : v){
                if(it.fi >= l && it.sc <= r){
                    se.insert(grundy[l][it.fi - 1] ^ grundy[it.sc + 1][r]);
                }
            }
            int mex = 0;
            while(se.count(mex)) ++mex;
            grundy[l][r] = mex;
        }
    }
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        vector<ii> v;
        int n; cin >> n;
        for(int i = 1; i <= n; ++i){
            int l, r; cin >> l >> r;
            v.push_back({l, r});
        }

        preGrundy(v);

        if(grundy[1][100] != 0) cout << "Alice\n";
        else cout << "Bob\n";
    }
    
    return 0;
}