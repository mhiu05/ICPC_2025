#include <bits/stdc++.h>
using namespace std;

static const int MOD   = 1000000007;
static const int ALPHA = 26;

// Cre: ChatGPT (Đã AC, chưa hiểu)
// https://wiki.vnoi.info/vi/algo/string/aho-corasick

struct Aho {
    struct Node {
        int next[ALPHA];
        int link;
        vector<int> out;    // chứa độ dài các từ kết thúc tại node này

        Node() {
            fill(begin(next), end(next), -1);
            link = 0;
        }
    };

    vector<Node> t;

    Aho(int reserve_nodes = 1) {
        t.reserve(reserve_nodes);
        t.emplace_back();  // root = 0
    }

    // chèn một từ vào trie
    void insert(const string &s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[u].next[c] == -1) {
                t[u].next[c] = t.size();
                t.emplace_back();
            }
            u = t[u].next[c];
        }
        t[u].out.push_back((int)s.size());
    }

    // xây suffix-link bằng BFS
    void build() {
        queue<int> q;
        // khởi tạo cho con của root
        for (int c = 0; c < ALPHA; ++c) {
            int v = t[0].next[c];
            if (v != -1) {
                t[v].link = 0;
                q.push(v);
            } else {
                t[0].next[c] = 0;  // phép fallback trực tiếp
            }
        }

        // BFS
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int c = 0; c < ALPHA; ++c) {
                int v = t[u].next[c];
                if (v != -1) {
                    // tìm link cho v
                    int j = t[u].link;
                    t[v].link = t[j].next[c];
                    // kế thừa output từ link
                    for (int len : t[t[v].link].out)
                        t[v].out.push_back(len);
                    q.push(v);
                } else {
                    // fallback: nếu không có next, dùng link của u
                    t[u].next[c] = t[t[u].link].next[c];
                }
            }
        }

        // loạt bỏ trùng độ dài (nếu có)
        for (auto &node : t) {
            auto &v = node.out;
            if (v.size() > 1) {
                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());
            }
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();

    int k;
    cin >> k;

    // reserve_nodes ≈ tổng độ dài từ điển + 1
    // bạn có thể điều chỉnh số này sát hơn với bài của bạn
    Aho aho((int)1e6 + 5);

    for (int i = 0; i < k; ++i) {
        string w;
        cin >> w;
        aho.insert(w);
    }
    aho.build();

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    int state = 0;
    for (int i = 1; i <= n; ++i) {
        int c = S[i-1] - 'a';
        // chuyển state với phép fallback đã lưu sẵn trong next[] của root
        state = aho.t[state].next[c];

        // duyệt mọi pattern kết thúc tại state
        for (int len : aho.t[state].out) {
            dp[i] = (dp[i] + dp[i - len]) % MOD;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
