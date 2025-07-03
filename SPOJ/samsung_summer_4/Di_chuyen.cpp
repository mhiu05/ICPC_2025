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
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int n, vs[101][101];
char A[101][101];

struct item{
    int xx, yy, step;
};

signed main(){
    faster;

    cin >> n;
    FOR(i, 0, n - 1){
        FOR(j, 0, n - 1){
            cin >> A[i][j];
        }
    }
    int a, b, c, d; cin >> a >> b >> c >> d;

    queue<item> q;
    item x;
    x.xx = a; x.yy = b; x.step = 0;
    q.push(x);

    while(!q.empty()){
        item tmp = q.front(); q.pop();
        
        if(tmp.xx == c && tmp.yy == d){
            cout << tmp.step;
            break;
        }

        item k;
        k.step = tmp.step + 1;
        
        k.xx = tmp.xx + 1; k.yy = tmp.yy;
        while(!vs[k.xx][k.yy] && k.xx < n && A[k.xx][k.yy] == '.'){
            vs[k.xx][k.yy] = 1;
            q.push(k);
            k.xx++;
        }

        k.xx = tmp.xx - 1; k.yy = tmp.yy;
        while(!vs[k.xx][k.yy] && k.xx >= 0 && A[k.xx][k.yy] == '.'){
            vs[k.xx][k.yy] = 1;
            q.push(k);
            k.xx--;
        }

        k.xx = tmp.xx; k.yy = tmp.yy + 1;
        while(!vs[k.xx][k.yy] && k.yy < n && A[k.xx][k.yy] == '.'){
            vs[k.xx][k.yy] = 1;
            q.push(k);
            k.yy++;
        }

        k.xx = tmp.xx; k.yy = tmp.yy - 1;
        while(!vs[k.xx][k.yy] && k.yy >= 0 && A[k.xx][k.yy] == '.'){
            vs[k.xx][k.yy] = 1;
            q.push(k);
            k.yy--;
        }
    }

    return 0;
}