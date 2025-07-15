#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modi = 1e9;
ll modl = 1e18;

// Dễ, bỏ qua

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		int stt, r; cin >> stt >> r;
		string s; cin >> s;
		cout << stt << " ";
		for(int i = 0; i < s.size(); ++i){
			for(int j = 1; j <= r; ++j){
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}