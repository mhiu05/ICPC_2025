#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
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

string quay1(string v) {
    string tmp = v;
    tmp[5] = v[1];
    tmp[8] = v[5];
    tmp[7] = v[8];
    tmp[3] = v[7];
    tmp[0] = v[3];
    tmp[1] = v[0];  
    return tmp;
}

string quay2(string v) {
    string tmp = v;
    tmp[2] = v[1];
    tmp[6] = v[2];
    tmp[9] = v[6];
    tmp[8] = v[9];
    tmp[4] = v[8];
    tmp[1] = v[4];
    return tmp;
}

string rvquay1(string v){
    string tmp = v;
    tmp[1] = v[5];
    tmp[5] = v[8];
    tmp[8] = v[7];
    tmp[7] = v[3];
    tmp[3] = v[0];
    tmp[0] = v[1];  
    return tmp;
}

string rvquay2(string v){
    string tmp = v;
    tmp[1] = v[2];
    tmp[2] = v[6];
    tmp[6] = v[9];
    tmp[9] = v[8];
    tmp[8] = v[4];
    tmp[4] = v[1];
    return tmp;
}

void solve(string a, string b){
    unordered_map<string, int> dist1, dist2;
    queue<string> q1, q2;
    dist1[a] = 0; dist2[b] = 0;
    q1.push(a); q2.push(b);

    while(!q1.empty()){
        string s = q1.front(); q1.pop();
        int n = dist1[s];
        
        if(n >= 16){
            break;
        }

        string next1 = quay1(s), next2 = quay2(s);

        if(b == next1 || b == next2){
            cout << n + 1;
            return;
        }

        if(!dist1.count(next1)){
            q1.push(next1);
            dist1[next1] = n + 1;
        }
        if(!dist1.count(next2)){
            q1.push(next2);
            dist1[next2] = n + 1;
        }
    }

    while(!q2.empty()){
        string s = q2.front(); q2.pop();
        int n = dist2[s];
        string next1 = rvquay1(s), next2 = rvquay2(s);

        if(dist1.count(next1)){
            cout << dist1[next1] + dist2[s] + 1;
            return;
        }
        if(dist1.count(next2)){
            cout << dist1[next2] + dist2[s] + 1;
            return;
        }

        if(!dist2.count(next1)){
            q2.push(next1);
            dist2[next1] = n + 1;
        }
        if(!dist2.count(next2)){
            q2.push(next2);
            dist2[next2] = n + 1;
        }
    }
}

signed main(){
    faster;

    string a(10, '0');
    string b = "1238004765";
    FOR(i, 0, 9){
        int x; cin >> x;
        a[i] = x + '0';
    }

    if(a == b){
        cout << 0;
        return 0;
    }

    solve(a, b);

    return 0;
}