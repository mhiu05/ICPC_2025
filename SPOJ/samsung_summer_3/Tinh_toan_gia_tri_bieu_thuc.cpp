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

int priority(string c){
    if(c == "*" || c == "/") return 2;
    if(c == "+" || c == "-") return 1;
    return 0;
}

ll cal(ll a, ll b, string s){
    if(s == "+") return a + b;
    if(s == "-") return a - b;
    if(s == "*") return a * b;
    if(s == "/") return a / b;
}

void solve(string s){
    vector<string> v;
    stack<string> st;
    FOR(i, 0, s.sz() - 1){
        if(s[i] == '('){
            st.push(string(1, s[i]));
        }
        else if(isdigit(s[i])){
            string tmp = "";
            while(i < s.sz() && isdigit(s[i])){
                tmp += s[i];
                ++i;
            }
            v.push_back(tmp);
            --i;
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != "("){
                v.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(string(1, s[i])) <= priority(st.top())){
                v.push_back(st.top());
                st.pop();
            }
            st.push(string(1, s[i]));
        }
    }
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }

    stack<ll> st1;
    FOR(i, 0, v.sz() - 1){
        if(isdigit(v[i][0])){
            st1.push(stoll(v[i]));
        }
        else{
            ll a = st1.top(); st1.pop();
            ll b = st1.top(); st1.pop();
            st1.push(cal(b, a, v[i]));
        }
    }
    cout << st1.top()<< endl;

}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        solve(s);
    }

    return 0;
}