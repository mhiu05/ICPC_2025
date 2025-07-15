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

map<char, int> mp;

void solve(string s){
    stack<int> st;
    FOR(i, 0, s.sz() - 1){
        if(s[i] == '(') {
            st.push(-1);
        }
        else if(isalpha(s[i])){
            st.push(mp[s[i]]);
        }
        else if(isdigit(s[i])){
            int x = st.top(); st.pop();
            st.push((s[i] - '0') * x);
        }
        else{
            int sum = 0;
            while(st.top() != -1){
                sum += st.top();
                st.pop();
            }
            st.pop(); // loại bỏ -1
            st.push(sum);
        }
    }

    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout << sum;
}

signed main(){
    faster;

    mp['C'] = 12; mp['H'] = 1; mp['O'] = 16;
    string s; cin >> s;
    solve(s);

    return 0;
}