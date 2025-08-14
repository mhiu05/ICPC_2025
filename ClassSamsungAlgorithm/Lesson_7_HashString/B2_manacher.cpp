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
const int MAXN = 2e5 + 5;

using namespace std;

// Thuật toán manacher O(n): https://wiki.vnoi.info/algo/string/manacher

string preprocess(string s){
    string t = "#";
    FOR(i, 0, s.sz() - 1){
        t += s[i];
        t += "#";
    }
    return t;
}

void solve(string s){
    s = preprocess(s);
    int max_len = 0;
    int c = 0, r = 0;
    int p[MAXN] = {0};

    FOR(i, 0, s.sz() - 1){
        int x = 2*c - i; // x đối xứng với i qua c
        if(i < r) p[i] = min(p[x], r - i);

        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < s.sz() && s[i - p[i] - 1] == s[i + p[i] + 1]) p[i]++;

        if(c + p[i] > r){
            c = i;
            r = c + p[i];
        }

        max_len = max(max_len, p[i]);
    }

    cout << max_len << endl;
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        solve(s);
    }

    return 0;
}