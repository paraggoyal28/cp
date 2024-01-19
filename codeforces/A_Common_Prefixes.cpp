#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    vector<ll> lengths(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> lengths[i];
    }
    string commonString(60, 'a');
    vector<string> strs(n + 1, commonString);
    for (ll i = 0; i < n; ++i)
    {
        ll j = 0;
        for (; j < lengths[i]; ++j)
        {
            strs[i + 1][j] = strs[i][j];
        }
        strs[i + 1][j] = (strs[i][j] - 'a' + 1) % 26 + 'a';
        cout << strs[i] << "\n";
    }
    cout << strs[n] << "\n";
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
