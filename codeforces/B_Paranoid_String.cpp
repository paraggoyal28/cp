#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> dp(n, 1);
    ll res = 1;
    for (ll i = 1; i < n; ++i)
    {
        ll j = i - 1;
        while (j >= 0 && s[i] != s[j])
        {
            dp[i] += dp[j];
            j -= 1;
        }
        res += dp[i];
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
