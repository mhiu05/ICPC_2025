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

ll x;

string solve(ll x){
    queue<pair<string, int>> q;

    q.push({"6", 6 % x});
    q.push({"8", 8 % x});
    
    while(!q.empty()){
        string s = q.front().fi;
        int r = q.front().sc;
        q.pop();

        if(s.sz() > 200) break;

        if(r == 0) return s;

        int r1 = (r*10 + 6) % x;
        q.push({s + "6", r1});

        int r2 = (r * 10 + 8) % x;
        if(s[s.sz() - 1] != '6') q.push({s + "8", r2});
    }
    return "-1";
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        cin >> x;
        cout << solve(x) << endl;
    }

    return 0;
}