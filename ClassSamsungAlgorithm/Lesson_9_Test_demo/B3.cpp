#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int idx, int val){
        for(; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sum(int idx){
        int r = 0;
        for(; idx > 0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
    // prefix sum [1..idx]
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    // Values A[i] in [0..N], we'll use indices 1..N+1 in BIT by mapping val -> val+1
    Fenwick bit(N+2);
    vector<ll> cnt(N+1, 0); // cnt[v] = # pairs (i<j) with A[j]=v and A[i]>v

    for(int i=0;i<N;i++){
        int v = A[i];
        int idx = v + 1; // map 0..N -> 1..N+1
        int prior_total = i; // number of elements before position i
        int leq_v = bit.sum(idx); // number of prior elements with value <= v
        int greater_v = prior_total - leq_v;
        if (v >= 0 && v <= N) cnt[v] += (ll)greater_v;
        // update BIT: add this element's value
        bit.add(idx, 1);
    }

    // Build answers: ans[X] = sum_{v=0}^{X-1} cnt[v]
    ll pref = 0;
    for(int X=0; X<=N-1; X++){
        cout << pref << '\n';
        pref += cnt[X];
    }

    return 0;
}
