#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
       
    }
    int res = 0;

    sort(a, a + n);
    cout << a[k];
}