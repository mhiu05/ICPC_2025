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

// A, B, C, D đồng phẳng <=> [vector(AB), vector(AC)].vector(AD) với []: Tích có hướng, . : Tích vô hướng
// (x1, y1, z1).(x2, y2, z2) = (x1.x2, y1.y2, z1.z2)
// [(a1, a2, a3), (b1, b2, b3)] = (det({a2,a3},{b2,b3}), det({a3,a1},{b3,b1}), det({a1,a2},{b1,b2}))

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        int xa, ya, za; cin >> xa >> ya >> za;
        int xb, yb, zb; cin >> xb >> yb >> zb;
        int xc, yc, zc; cin >> xc >> yc >> zc;
        int xd, yd, zd; cin >> xd >> yd >> zd;

        // Tính tọa độ vector AB, AC, AD
        int xab = xb - xa, yab = yb - ya, zab = zb - za;
        int xac = xc - xa, yac = yc - ya, zac = zc - za;
        int xad = xd - xa, yad = yd - ya, zad = zd - za;

        // Tính [AB, AC] = (X1, X2, X3), S = [AB, AC].AD 
        int X1 = yab * zac - zab * yac, X2 = zab * xac - xab * zac, X3 = xab * yac - yab * xac;
        int S = X1 * xad + X2 * yad + X3 * zad;
        if(S == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}