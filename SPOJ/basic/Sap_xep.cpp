#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modi = 1e9;
ll modl = 1e18;


int main(){
	int n; cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	sort(a, a + n);
	for(int x : a) cout << x << endl;
	return 0;
}