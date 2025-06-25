#include <bits/stdc++.h>
#define endl "\n"
#define second sc
#define first fi

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 1;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

string sumStr(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);
    while (a.size() != b.size())
    {
        b = "0" + b;
    }
    string ans = "";
    int nho = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        int x = (a[i] - '0') + (b[i] - '0') + nho;
        nho = x / 10;
        int kq = x % 10;
        ans = to_string(kq) + ans;
    }
    if (nho != 0)
        ans = "1" + ans;
    return ans;
}

string productStr(string a, int b)
{
    int carry = 0;
    string res;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        int s = (a[i] - '0') * b + carry;
        carry = s / 10;
        res += (char)(s % 10 + '0');
    }

    if (carry > 0)
        while (carry != 0)
        {
            res += (char)(carry % 10 + '0');
            carry /= 10;
        }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    faster();
    int n, m;
    cin >> n >> m;
    string tmp1 = "1";
    for (int i = 1; i <= n; ++i)
    {
        tmp1 = productStr(tmp1, 2);
    }
    string tmp2 = "1";
    for (int i = 1; i <= m; ++i)
    {
        tmp2 = productStr(tmp2, 3);
    }
    string ans = sumStr(tmp1, tmp2);
    cout << ans[0];
    return 0;
}