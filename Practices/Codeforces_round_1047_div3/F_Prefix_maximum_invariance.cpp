#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    a[0] = 1e18;
    
    vector<ll> al(n+1), bl(n+1);
    vector<int> st; // use vector as stack
    st.push_back(0);
    
    for (int i = 1; i <= n; i++) {
        while (a[st.back()] < a[i]) {
            st.pop_back();
        }
        al[i] = st.back();
        
        // Binary search directly in the vector stack
        int left = 0, right = st.size() - 1;
        int idx = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[st[mid]] >= b[i]) {
                idx = st[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        bl[i] = idx;
        
        st.push_back(i);
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            ans += (ll)i * (n - i + 1);
        } else if (a[i] > b[i]) {
            ans += (ll)al[i] * (n - i + 1);
        } else {
            ans += (ll)bl[i] * (n - i + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}