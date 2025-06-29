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

int priority(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void solve(string s){
    stack<char> st;
    FOR(i, 0, s.sz() - 1){
        if(s[i] == '(') st.push(s[i]);
        else if(isalpha(s[i])) cout << s[i];
        else if(s[i] == ')'){
            while(1){
                char c = st.top(); st.pop();
                if(c == '(') break;
                cout << c;
            }
        }
        else{
            if(!st.empty()){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else st.push(s[i]);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
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