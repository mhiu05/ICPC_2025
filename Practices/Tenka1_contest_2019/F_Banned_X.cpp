#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

// Code TLE

// fast pow (if needed)
ll modpow(ll a, ll e) {
    ll r = 1;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

// ---------- Approach A: mask-based (only when X <= 60) ----------
bool solve_mask_uint64(int N, int X, ll &out) {
    if (X == 0) {
        // forbid any zero -> choices {1,2} only
        out = modpow(2, N);
        return true;
    }
    if (X > 60) return false; // can't fit into uint64 mask safely

    if (X == 1) {
        // forbid any '1' (since substring sum 1 -> any single 1), but zeros allowed and twos allowed
        // count sequences length N over {0,2} = 2^N
        out = modpow(2, N);
        return true;
    }

    int bits = X - 1; // track sums 1..X-1 -> bit positions 0..bits-1
    uint64_t fullmask = (bits == 64) ? ~0ULL : ((1ULL << bits) - 1ULL);

    auto trans_mask = [&](uint64_t mask, int d, uint64_t &nmask)->bool{
        // return true if transition leads to forbidden (some suffix sum becomes exactly X)
        // check if any s in [1..X-1] such that s + d == X -> s == X-d
        if (d == X) return true;
        if (d > 0) {
            int need = X - d; // s == need
            if (need >= 1 && need <= X-1) {
                int bitpos = need - 1;
                if ((mask >> bitpos) & 1ULL) return true;
            }
        }
        // also if d == X -> handled; but d is 0/1/2 so only possible if X<=2 handled above
        // now compute new mask:
        uint64_t shifted = (d == 0) ? mask : ((mask << d) & fullmask);
        if (d > 0) shifted |= (1ULL << (d - 1)); // add singleton suffix sum d
        nmask = shifted & fullmask;
        return false;
    };

    // BFS build reachable masks
    unordered_map<uint64_t,int> id;
    vector<uint64_t> states;
    vector<array<int,3>> nxt;
    queue<uint64_t> q;
    uint64_t start = 0;
    id[start] = 0;
    states.push_back(start);
    nxt.push_back({-1,-1,-1});
    q.push(start);

    while (!q.empty()) {
        uint64_t m = q.front(); q.pop();
        int sid = id[m];
        for (int d=0; d<=2; ++d) {
            uint64_t nm;
            bool bad = trans_mask(m,d,nm);
            if (bad) {
                nxt[sid][d] = -1; // forbidden transition
            } else {
                auto it = id.find(nm);
                if (it == id.end()) {
                    int nid = (int)states.size();
                    id[nm] = nid;
                    states.push_back(nm);
                    nxt.emplace_back(array<int,3>{-1,-1,-1});
                    q.push(nm);
                    nxt[sid][d] = nid;
                } else {
                    nxt[sid][d] = it->second;
                }
            }
        }
        // safety: avoid explosion: if states too many, bail to false (fallback)
        if ((int)states.size() > 2000000) return false;
    }

    int S = (int)states.size();
    // DP across N steps
    vector<ll> dp(S,0), ndp(S,0);
    dp[0] = 1;
    for (int len=0; len < N; ++len) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int s=0; s<S; ++s) {
            if (dp[s]==0) continue;
            for (int d=0; d<=2; ++d) {
                int to = nxt[s][d];
                if (to == -1) continue; // forbidden
                ndp[to] += dp[s];
                if (ndp[to] >= MOD) ndp[to] -= MOD;
            }
        }
        dp.swap(ndp);
    }
    ll ans = 0;
    for (int s=0; s<S; ++s) ans = (ans + dp[s]) % MOD;
    out = ans;
    return true;
}

// ---------- Approach B: fallback Aho-Corasick with pruning ----------
struct AC {
    struct Node {
        int nx[3];
        int link;
        bool out;
        Node(){ nx[0]=nx[1]=nx[2]=-1; link=0; out=false; }
    };
    vector<Node> t;
    AC(){ t.emplace_back(); }
    void add(const vector<int>& pat){
        int v=0;
        for(int c:pat){
            if(t[v].nx[c]==-1){ t[v].nx[c]= (int)t.size(); t.emplace_back(); }
            v = t[v].nx[c];
        }
        t[v].out = true;
    }
    void build(){
        queue<int> q;
        t[0].link = 0;
        for(int c=0;c<3;++c){
            if(t[0].nx[c] != -1){ t[t[0].nx[c]].link = 0; q.push(t[0].nx[c]); }
            else t[0].nx[c] = 0;
        }
        while(!q.empty()){
            int v=q.front(); q.pop();
            t[v].out = t[v].out | t[t[v].link].out;
            for(int c=0;c<3;++c){
                if(t[v].nx[c] != -1){
                    t[t[v].nx[c]].link = t[t[v].link].nx[c];
                    q.push(t[v].nx[c]);
                } else {
                    t[v].nx[c] = t[t[v].link].nx[c];
                }
            }
        }
    }
};

void collect_minimal_patterns_pruned(int N, int X, vector<vector<int>>& patterns) {
    // Generate sequences length <= min(N, X) with sum==X and first/last != 0
    // and no proper substring with sum==X (minimal).
    int Lmax = min(N, X);
    vector<int> cur;
    function<void(int,int)> dfs = [&](int pos, int sum){
        if (sum > X) return;
        if ((int)cur.size() > Lmax) return;
        if (sum == X) {
            int L = (int)cur.size();
            if (L==0) return;
            if (cur.front()==0 || cur.back()==0) return; // prune leading/trailing zero (not minimal)
            // check no proper substring sums to X
            bool ok = true;
            for (int i=0;i<L && ok;++i){
                int s=0;
                for (int j=i;j<L;++j){
                    s += cur[j];
                    if (s == X){
                        if (!(i==0 && j==L-1)){ ok = false; break; }
                    }
                    if (s > X) break;
                }
            }
            if (ok) patterns.push_back(cur);
            return;
        }
        // try append 1 or 2 first to ensure start non-zero when pos==0
        for (int d=0; d<=2; ++d) {
            if (pos==0 && d==0) continue; // no leading zero
            cur.push_back(d);
            dfs(pos+1, sum + d);
            cur.pop_back();
        }
    };
    dfs(0,0);
}

bool solve_aho(int N, int X, ll &out) {
    if (X == 0) { out = modpow(2, N); return true; }
    vector<vector<int>> patterns;
    collect_minimal_patterns_pruned(N, X, patterns);
    // if no patterns -> all sequences allowed
    if (patterns.empty()) {
        // every string of length N over {0,1,2}
        out = modpow(3, N);
        return true;
    }
    AC ac;
    for (auto &p: patterns) ac.add(p);
    ac.build();
    int S = (int)ac.t.size();
    // DP
    vector<ll> dp(S,0), ndp(S,0);
    dp[0] = 1;
    for (int len=0; len<N; ++len) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int s=0;s<S;++s){
            if (dp[s]==0) continue;
            if (ac.t[s].out) continue;
            for (int c=0;c<3;++c){
                int ns = ac.t[s].nx[c];
                if (ac.t[ns].out) continue;
                ndp[ns] += dp[s];
                if (ndp[ns] >= MOD) ndp[ns] -= MOD;
            }
        }
        dp.swap(ndp);
    }
    ll ans=0;
    for(int s=0;s<S;++s) if(!ac.t[s].out) ans = (ans + dp[s]) % MOD;
    out = ans;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, X;
    if (!(cin >> N >> X)) return 0;

    ll ans;
    // prefer fast mask method when possible
    if (X <= 60) {
        bool ok = solve_mask_uint64(N, X, ans);
        if (ok) {
            cout << ans % MOD << "\n";
            return 0;
        }
        // else fallthrough
    }
    // fallback to pruned Aho approach
    solve_aho(N, X, ans);
    cout << ans % MOD << "\n";
    return 0;
}
