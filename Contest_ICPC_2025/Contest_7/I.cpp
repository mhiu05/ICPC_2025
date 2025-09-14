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

int cal(int x1, int y1, int x2, int y2){
    return (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
}

signed main(){
    faster;

    int xA, yA, xB, yB, xC, yC; cin >> xA >> yA >> xB >> yB >> xC >> yC;    
    int AB = cal(xA, yA, xB, yB);
    int AC = cal(xA, yA, xC, yC);
    int BC = cal(xB, yB, xC, yC);

    if(AB + AC == BC || AB + BC == AC || AC + BC == AB){
        cout << "Yes";
    }
    else cout << "No";


    return 0;
}