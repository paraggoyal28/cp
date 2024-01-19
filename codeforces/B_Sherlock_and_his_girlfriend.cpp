#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    vector<ll> color(n + 2, 1);
    for (ll c = 2; c * c <= n + 1; ++c)
    {
        if (color[c] == 1)
        {
            for (ll j = c * c; j <= n + 1; j += c)
            {
                color[j] = 2;
            }
        }
    }
    if (n <= 2)
    {
        cout << "1\n";
    }
    else
    {
        cout << "2\n";
    }

    for (ll i = 2; i <= n + 1; ++i)
    {
        cout << color[i] << " ";
    }
    cout << "\n";
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
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
