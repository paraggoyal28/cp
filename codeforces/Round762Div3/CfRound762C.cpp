#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string removeStartZero(string &str)
{
    int i = 0;
    int n = str.length();
    while (i < n && str[i] == '0')
    {
        i += 1;
    }
    return i == n ? "0" : str.substr(i);
}

string solve(string &a, string &b)
{
    int i = a.length() - 1;
    int j = b.length() - 1;
    string res = "";
    while (i >= 0 && j >= 0)
    {
        if (a[i] - '0' > b[j] - '0')
        {
            if (j == 0)
                return "-1";
            int num = (b[j - 1] - '0') * 10 + (b[j] - '0');
            int sub = (num - (a[i] - '0'));
            if (sub > 9 || sub < 1)
            {
                return "-1";
            }
            res += sub + '0';
            j -= 2;
        }
        else
        {
            res += b[j] - a[i] + '0';
            j -= 1;
        }
        i -= 1;
    }
    if (i >= 0)
        return "-1";
    while (j >= 0)
    {
        res += b[j];
        j -= 1;
    }
    reverse(res.begin(), res.end());
    res = removeStartZero(res);
    return res;
}

int main()
{
    ll tests;
    cin >> tests;
    while (tests--)
    {
        string a, s;
        cin >> a >> s;
        cout << solve(a, s) << "\n";
    }
}