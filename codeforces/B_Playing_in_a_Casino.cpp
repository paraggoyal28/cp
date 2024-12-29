#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> cards[m];
        ll c;
        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < m; ++j)
            {
                cin >> c;
                cards[j].push_back(c);
            }
        }
        for (ll i = 0; i < m; ++i)
        {
            sort(cards[i].begin(), cards[i].end());
        }

        ll ans = 0;
        for (ll i = 0; i < m; ++i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                ans += cards[i][j] * (j) + cards[i][j] * (-1 * (n - 1 - j));
            }
        }
        cout << ans << "\n";
    }
}