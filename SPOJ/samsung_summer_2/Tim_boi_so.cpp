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


void solve(ll n){
    queue<pair<string, ll>> q;
    q.push({"9", 9 % n});
    while(!q.empty()){
        string s = q.front().fi;
        ll r = q.front().sc;
        q.pop();
        if(r == 0){
            cout << s << endl;
            return;
        }
        q.push({s + "0", (10*r + 0) % n});
        q.push({s + "9", (10*r + 9) % n});
    }
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        solve(n);
    }

    return 0;
}