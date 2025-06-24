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

using namespace std;

int a[15][15], n;
vector<string> ans;

void Try(int i, int j, string s){
    if(i == n && j == n){
        ans.push_back(s);
        return;
    }
    
    if(i + 1 <= n && a[i + 1][j]){
        Try(i + 1, j, s + "D");
    }

    if(j + 1 <= n && a[i][j + 1]){
        Try(i, j + 1, s + "R");
    }
}

int main(){
    faster;
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> a[i][j];
            }
        }
        ans.clear();

        if(a[1][1] && a[n][n]) Try(1, 1, "");

        if(ans.size() == 0){
            cout << -1 << endl;
        }
        else{
            sort(ans.begin(), ans.end());
            for(string s : ans) cout << s << " ";
            cout << endl;
        }
    }
    return 0;
}