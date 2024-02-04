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
const int oo = 1e18;

void solve()
{
    int a, b;
    cin >> a >> b;
    string mines;
    cin >> mines;
    vector<int> pos;
    for (int i = 0, n = mines.length(); i < n; ++i)
    {
        if (mines[i] == '1')
        {
            pos.push_back(i);
        }
    }
    if (pos.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (pos.size() == 1)
    {
        cout << a << endl;
        return;
    }
    int pay = 0;
    for (int i = 1, m = pos.size(); i < m; ++i)
    {
        if (pos[i] != pos[i - 1] + 1)
        {
            int diff = pos[i] - pos[i - 1] - 1;
            if (diff * b < a)
            {
                pay += diff * b;
            }
            else
            {
                pay += a;
            }
        }
    }
    pay += a;
    cout << pay << endl;
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
