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

// 2,3,4 % 5 quy luật chu kỳ 4

int module(string s){
    ll x = 0;
    for(char c : s){
        x = 10*x + (c - '0');
        x %= 4;
    }
    return x % 4;
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        string s; cin >> s;

        int dk = module(s);

        if(dk == 1){
            cout << (1 + 2 + 3 + 4) % 5 << endl;
        }
        else if(dk == 2){
            cout << (1 + 4 + 4 + 1) % 5 << endl; 
        }
        else if(dk == 3){
            cout << (1 + 3 + 2 + 4) % 5 << endl;
        }
        else cout << (1 + 1 + 1 + 1) % 5 << endl;
    }

    return 0;
}