#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;

int64 Fact[MAXN], InvFact[MAXN];

// Lũy thừa nhị phân
int64 modPow(int64 base, int64 exp, int mod = MOD) {
    int64 res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// Chuẩn bị factorial và inverse factorial
void prepare() {
    Fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        Fact[i] = Fact[i - 1] * i % MOD;
    }
    InvFact[MAXN - 1] = modPow(Fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        InvFact[i] = InvFact[i + 1] * (i + 1) % MOD;
    }
}

int64 P(int n, int k) { // nPk
    if (k < 0 || k > n) return 0;
    return Fact[n] * InvFact[n - k] % MOD;
}

int64 C(int n, int k) { // nCk
    if (k < 0 || k > n) return 0;
    return Fact[n] * InvFact[k] % MOD % MOD * InvFact[n - k] % MOD;
}

void solve() {
    int n, m, A, B;
    cin >> n >> m >> A >> B;

    int64 res = 0;
    int64 invN = (n % MOD == 0 ? 0 : modPow(n % MOD, MOD - 2));

    for (int d = 1; d <= n - 1; d++) {
        int expN = n - d - 2;
        int64 powNterm = (expN >= 0 ? modPow(n % MOD, expN) : invN);

        int64 tmp1 = P(n - 2, d - 1) * (d + 1) % MOD;
        tmp1 = tmp1 * powNterm % MOD;

        int expM = n - d - 1;
        int64 powMterm = (expM >= 0 ? modPow(m % MOD, expM) : 0);

        int64 tmp2 = C(m - 1, d - 1) * powMterm % MOD;

        res += tmp1 * tmp2 % MOD;
        if (res >= MOD) res -= MOD;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prepare();
    solve();

    return 0;
}
