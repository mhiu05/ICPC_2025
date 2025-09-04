#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600005;
const int MX_LOG = 25;

class BinaryTrie {
private:
    struct Node {
        Node* child[2];
        Node() {
            child[0] = child[1] = nullptr;
        }
    };

    Node* root;
    int total_xor;

    int getBit(int num, int pos) {
        return (num >> pos) & 1;
    }

public:
    BinaryTrie() {
        root = new Node();
        total_xor = 0;
    }

    void insert(int num) {
        Node* current = root;
        for (int bit = MX_LOG - 1; bit >= 0; bit--) {
            int idx = getBit(num, bit);
            if (current->child[idx] == nullptr) {
                current->child[idx] = new Node();
            }
            current = current->child[idx];
        }
    }

    int getMex() {
        int mex = 0;
        Node* current = root;
        for (int bit = MX_LOG - 1; bit >= 0; bit--) {
            int idx = getBit(total_xor, bit);
            mex <<= 1;

            if (current->child[idx] != nullptr) {
                current = current->child[idx];
            } else {
                mex |= 1;
                current = current->child[1 - idx];
            }
        }
        return mex;
    }

    void updateXor(int x) {
        total_xor ^= x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<bool> exists(MAXN, false);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < MAXN) {
            exists[num] = true;
        }
    }

    BinaryTrie trie;
    for (int i = 0; i < MAXN; i++) {
        if (!exists[i]) {
            trie.insert(i);
        }
    }

    while (q--) {
        int x;
        cin >> x;
        trie.updateXor(x);
        cout << trie.getMex() << '\n';
    }

    return 0;
}