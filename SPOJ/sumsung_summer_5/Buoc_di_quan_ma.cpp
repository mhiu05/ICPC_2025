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

struct item{
    int xx, yy, step;
};

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        int x = s1[0] - 'a' + 1, y = s1[1] - '0';
        int u = s2[0] - 'a' + 1, v = s2[1] - '0';

        item I;
        I.xx = x; I.yy = y; I.step = 0;
        int vs[10][10];
        memset(vs, 0, sizeof(vs));

        queue<item> q;
        q.push(I);
        vs[I.xx][I.yy] = 1;
        
        while(!q.empty()){
            item tmp = q.front(); q.pop();

            if(tmp.xx == u && tmp.yy == v){
                cout << tmp.step << endl;
                break;
            }

            item tmp1 = tmp;
            tmp1.xx -= 1; tmp1.yy -= 2; tmp1.step += 1;
            if(tmp1.xx >= 1 && tmp1.xx <= 8 && tmp1.yy >= 1 && tmp1.yy <= 8 && !vs[tmp1.xx][tmp1.yy]){
                vs[tmp1.xx][tmp1.yy] = 1;
                q.push(tmp1);
            }

            tmp1 = tmp;
            tmp1.xx += 1; tmp1.yy -= 2; tmp1.step += 1;
            if(tmp1.xx >= 1 && tmp1.xx <= 8 && tmp1.yy >= 1 && tmp1.yy <= 8 && !vs[tmp1.xx][tmp1.yy]){
                vs[tmp1.xx][tmp1.yy] = 1;
                q.push(tmp1);
            }

            tmp1 = tmp;
            tmp1.xx -= 2; tmp1.yy -= 1; tmp1.step += 1;
            if(tmp1.xx >= 1 && tmp1.xx <= 8 && tmp1.yy >= 1 && tmp1.yy <= 8 && !vs[tmp1.xx][tmp1.yy]){
                vs[tmp1.xx][tmp1.yy] = 1;
                q.push(tmp1);
            }

            tmp1 = tmp;
            tmp1.xx += 2; tmp1.yy -= 1; tmp1.step += 1;
            if(tmp1.xx >= 1 && tmp1.xx <= 8 && tmp1.yy >= 1 && tmp1.yy <= 8 && !vs[tmp1.xx][tmp1.yy]){
                vs[tmp1.xx][tmp1.yy] = 1;
                q.push(tmp1);
            }

            tmp1 = tmp;
            tmp1.xx -= 2; tmp1.yy += 1; tmp1.step += 1;
            if(tmp1.xx >= 1 && tmp1.xx <= 8 && tmp1.yy >= 1 && tmp1.yy <= 8 && !vs[tmp1.xx][tmp1.yy]){
                vs[tmp1.xx][tmp1.yy] = 1;
                q.push(tmp1);
            }

            tmp1 = tmp;
            tmp1.xx += 2; tmp1.yy += 1; tmp1.step += 1;
            if(tmp1.xx >= 1 && tmp1.xx <= 8 && tmp1.yy >= 1 && tmp1.yy <= 8 && !vs[tmp1.xx][tmp1.yy]){
                vs[tmp1.xx][tmp1.yy] = 1;
                q.push(tmp1);
            }

            tmp1 = tmp;
            tmp1.xx -= 1; tmp1.yy += 2; tmp1.step += 1;
            if(tmp1.xx >= 1 && tmp1.xx <= 8 && tmp1.yy >= 1 && tmp1.yy <= 8 && !vs[tmp1.xx][tmp1.yy]){
                vs[tmp1.xx][tmp1.yy] = 1;
                q.push(tmp1);
            }

            tmp1 = tmp;
            tmp1.xx += 1; tmp1.yy += 2; tmp1.step += 1;
            if(tmp1.xx >= 1 && tmp1.xx <= 8 && tmp1.yy >= 1 && tmp1.yy <= 8 && !vs[tmp1.xx][tmp1.yy]){
                vs[tmp1.xx][tmp1.yy] = 1;
                q.push(tmp1);
            }
        }
    }

    return 0;
}