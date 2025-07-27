#include<bits/stdc++.h>
using namespace std;
int f[1000][1000];
int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;

    for(int i = 0; i < min(s1.size(), s2.size()); ++i){
        f[i][i] = 1;
    }

    for(int i = 1 ; i < s1.size() ; i++)
    {
        for(int j = 1 ; j < s2.size(); j++)
        {
            if(s1[i - 1] == s2[j - 1]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
    }
    cout<<f[s1.size() - 1][s2.size() - 1];
}
