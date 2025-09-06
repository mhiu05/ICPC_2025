#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 2), Left(n + 2), Right(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // sentinel
    a[0] = a[n + 1] = INT_MAX;

    for (int i = 0; i <= n + 1; i++) {
        Left[i] = i - 1;
        Right[i] = i + 1;
    }

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 2; i <= n - 1; i++) {
        pq.push({a[i], i});
    }

    long long res = 0;
    while (!pq.empty()) {
        auto [val, i] = pq.top();
        pq.pop();

        int L = Left[i], R = Right[i];
        res += min(a[L], a[R]);

        if (a[Left[R]] < a[L]) Left[R] = L;
        if (a[Right[L]] < a[R]) Right[L] = R;
    }

    cout << res << "\n";
    return 0;
}
