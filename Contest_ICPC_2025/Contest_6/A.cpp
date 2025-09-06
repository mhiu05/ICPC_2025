#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> cnt(3, 0);
    int res = 1;

    for (char c : s) {
        cnt[c - 'A']++;
        if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
            cnt[0]--; 
            cnt[1]--; 
            cnt[2]--;
        }
        res = max({res, cnt[0], cnt[1], cnt[2]});
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();    
    return 0;
}
