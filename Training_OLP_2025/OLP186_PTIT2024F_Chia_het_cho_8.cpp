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

// với s.sz() >= 3, s % 8 == 0 <=> 3 chữ số cuối cùng % 8 == 0 (vì 1000 % 8 == 0)

void solve(string s){
    if(s.sz() == 1){
        if((s[0] - '0') % 8 == 0) cout << "YES";
        else cout << "NO";
    }
    else if(s.sz() == 2){
        if((10*(s[0] - '0') + (s[1] - '0')) % 8 == 0 || (10*(s[1] - '0') + (s[0] - '0')) % 8 == 0) cout << "YES";
        else cout << "NO";
    }
    else{
        map<int, int> mp;
        FOR(i, 0, s.sz() - 1){
            mp[s[i] - '0']++;
        }
        int check = 0;
        for(int i = 104; i <= 992; i += 8){
            mp[i % 10]--; 
            mp[(i / 10) % 10]--;
            mp[i / 100]--;
            if(mp[i % 10] >= 0 && mp[(i / 10) % 10] >= 0 && mp[i / 100] >= 0){
                check = 1;
                break;
            }
            mp[i % 10]++; 
            mp[(i / 10) % 10]++;
            mp[i / 100]++;
        }
        if(check) cout << "YES";
        else cout << "NO";
    }
}

int main(){
    faster;

    string s; cin >> s;
    solve(s);

    return 0;
}