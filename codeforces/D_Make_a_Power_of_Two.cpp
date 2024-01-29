#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define back(v) v.rbegin(), v.rend()
#define nl "\n"
#define yes cout << "YES" << nl;
#define no cout << "NO" << nl;
#define deb(a) cerr << #a << "=" << (a) << nl;
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;
#define mod 1000000007
const int oo = 2 * 1e18;

int numberOfBits(int num)
{
    int bits = 0;
    for (int i = 31; i >= 0; --i)
    {
        if (num & (1 << i))
        {
            bits++;
        }
    }
    return bits;
}

bool isPowerOfTwo(int num)
{
    return numberOfBits(num) == 1;
}

ld convertToInt(string str)
{
    ld res = 0;
    int n = str.length();
    for (int i = 0; i < n; ++i)
    {
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

bool isPowerOfTwo(string str)
{
    if (str == "" || str[0] == '0')
        return false;
    ld num = convertToInt(str);
    if (num > oo)
        return false;
    return isPowerOfTwo(num);
}

int solve(string s, string t)
{
    int tp = 0;
    int sp = 0;
    int taken = 0;
    while (sp < s.length() && tp < t.length())
    {
        if (s[sp] == t[tp])
        {
            taken++;
            tp++;
        }
        sp++;
    }
    return (int)s.length() - taken + (int)t.length() - taken;
}

void solve()
{
    vector<string> ts;
    for (int p2 = 1; p2 <= oo; p2 *= 2)
    {
        ts.push_back(to_string(p2));
    }
    string n;
    cin >> n;
    int ans = n.length() + 1;
    for (auto p2 : ts)
    {
        ans = min(ans, solve(n, p2));
    }
    cout << ans << "\n";
}

signed main()
{
    FastIO;

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
