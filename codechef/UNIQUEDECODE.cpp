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
    string s;
    cin >> s;
    int ab_end_a = 0;
    int ab_end_b = 0;
    int a_end_a = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'a')
        {
            ab_end_a = (ab_end_a + ab_end_b) % mod;
            a_end_a = (2 * a_end_a + 1) % mod;
        }
        else
        {
            ab_end_b = (ab_end_a + ab_end_b + a_end_a) % mod;
        }
    }
    cout << (ab_end_b + a_end_a) % mod << nl;
}
signed main()
{
    FastIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
