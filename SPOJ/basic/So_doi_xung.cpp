#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modi = 1e9;
ll modl = 1e18;

int check (string s){
	for(int i = 0; i < s.size(); ++i){
		if(s[i] != s[s.size() - i - 1]) return 0;
	}
	return 1;
}

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		if(check(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}