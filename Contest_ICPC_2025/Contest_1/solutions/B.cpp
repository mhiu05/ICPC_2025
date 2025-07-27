#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// Đề:
// Cho xâu S độ dài n và từ điển gồm k từ. Tính số cách ghép các từ trong từ điển để tạo thành xâu S(1 từ có thể sd nhiều lần)
// 1 <= n <= 5000, 1 <= k <= 10^5
// input:              output: 2
// ababc                 
// 4
// ab
// abab 
// c
// cb  

// Cre: ChatGPT (Chưa submit nên chưa biết AC không)


struct Triplet {
    int len;
    LL h1;
    LL h2;
    Triplet(int l, LL a, LL b) : len(l), h1(a), h2(b) {}
    bool operator==(const Triplet &other) const {
        return len == other.len && h1 == other.h1 && h2 == other.h2;
    }
};

struct Hash {
    size_t operator()(const Triplet& t) const {
        return (static_cast<size_t>(t.len) * 1000000007LL + 
               (static_cast<size_t>(t.h1) * 1000000009LL + 
               static_cast<size_t>(t.h2);
    }
};

signed main(){
    faster;

    string S;
    cin >> S;
    int K;
    cin >> K;
    vector<string> words(K);
    int max_len = 0;
    for (int i = 0; i < K; i++) {
        cin >> words[i];
        if (static_cast<int>(words[i].length()) > max_len) 
            max_len = words[i].length();
    }

    unordered_set<Triplet, Hash> globalSet;
    for (string w : words) {
        int L = w.length();
        LL h1 = 0;
        LL h2 = 0;
        for (char c : w) {
            h1 = (h1 * base + static_cast<LL>(c)) % mod1;
            h2 = (h2 * base + static_cast<LL>(c)) % mod2;
        }
        globalSet.insert(Triplet(L, h1, h2));
    }

    int N = S.length();
    vector<LL> H1(N+1, 0), H2(N+1, 0);
    vector<LL> pow1(N+1, 1), pow2(N+1, 1);
    for (int i = 0; i < N; i++) {
        H1[i+1] = (H1[i] * base + static_cast<LL>(S[i])) % mod1;
        H2[i+1] = (H2[i] * base + static_cast<LL>(S[i])) % mod2;
        pow1[i+1] = (pow1[i] * base) % mod1;
        pow2[i+1] = (pow2[i] * base) % mod2;
    }

    vector<LL> dp(N+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        int L_max = min(i, max_len);
        for (int L = 1; L <= L_max; L++) {
            int start = i - L;
            LL hash1 = (H1[i] - H1[start] * pow1[L] % mod1 + mod1) % mod1;
            LL hash2 = (H2[i] - H2[start] * pow2[L] % mod2 + mod2) % mod2;
            if (globalSet.find(Triplet(L, hash1, hash2)) != globalSet.end()) {
                dp[i] = (dp[i] + dp[i - L]) % MOD;
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}