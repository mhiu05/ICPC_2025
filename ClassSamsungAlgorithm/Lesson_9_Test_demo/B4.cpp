#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // coordinate compression
    vector<ll> vals;
    vals.reserve(n);
    for (int i = 1; i <= n; ++i) vals.push_back(a[i]);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = (int)vals.size();

    // map value -> compressed id using unordered_map (built once)
    unordered_map<ll,int> id;
    id.reserve(m * 2 + 10);
    id.max_load_factor(0.7f);
    for (int i = 0; i < m; ++i) id[vals[i]] = i;

    // compressed indices per position
    vector<int> comp(n+1);
    for (int i = 1; i <= n; ++i) comp[i] = id[a[i]];

    // allocate flat prefix array S of size (n+1)*(n+1) (1-based)
    // S[idx(i,j)] will store prefix after processing
    const int W = n + 1;
    size_t Ssz = (size_t)W * (size_t)W;
    // allocate contiguous memory and zero it
    vector<ll> S;
    try {
        S.assign(Ssz, 0LL);
    } catch(...) {
        // fallback if memory allocation failed
        cerr << "Memory allocation failed\n";
        return 0;
    }
    auto idx = [&](int i, int j)->size_t { return (size_t)i * W + (size_t)j; };

    // freq array reused per i; using simple fill (m <= 5000 so fill cost acceptable)
    vector<int> freq(m);

    // Build M (store into S[i][k] as counts)
    for (int i = 1; i <= n; ++i) {
        // reset freq to zeros
        if (m <= 64) { // small m: unrolled fill maybe faster
            for (int t = 0; t < m; ++t) freq[t] = 0;
        } else {
            std::fill(freq.begin(), freq.end(), 0);
        }
        for (int k = i + 2; k <= n; ++k) {
            // add j = k-1 into freq (j in [i+1, k-1])
            ++freq[ comp[k-1] ];
            ll need = -(a[i] + a[k]);
            auto it = id.find(need);
            if (it != id.end()) {
                int need_idx = it->second;
                int cntj = freq[ need_idx ];
                if (cntj) {
                    S[ idx(i, k) ] += (ll)cntj;
                }
            }
        }
    }

    // make S into 2D prefix: S[i][j] = sum_{x=1..i, y=1..j} M[x][y]
    // Use row-sum trick to reduce operations
    for (int i = 1; i <= n; ++i) {
        ll rowsum = 0;
        size_t base = (size_t)i * W;
        size_t prevbase = (size_t)(i-1) * W;
        for (int j = 1; j <= n; ++j) {
            rowsum += S[base + j];              // sum M[i][1..j]
            S[base + j] = S[prevbase + j] + rowsum; // prefix from previous rows + this rowsum
        }
    }

    // answer queries
    while (q--) {
        int l, r; cin >> l >> r;
        size_t A = idx(r, r);
        size_t B = idx(l-1, r);
        size_t C = idx(r, l-1);
        size_t D = idx(l-1, l-1);
        ll ans = S[A] - S[B] - S[C] + S[D];
        cout << ans << '\n';
    }
    return 0;
}
