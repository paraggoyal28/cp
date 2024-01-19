#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100002;
const int B = 322;
ll pre[B][B + N]{}, S[B][N + B]{};

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (ll d = 1; d < B; ++d)
    {
        for (ll i = 0; i < n; ++i)
        {
            S[d][i + d] = S[d][i] + a[i] * (i / d + 1);
            pre[d][i + d] = pre[d][i] + a[i];
        }
    }

    while (q--)
    {
        ll s, d, k;
        cin >> s >> d >> k;
        s--;
        ll ans = 0;
        if (d >= B)
        {
            for (ll i = 0; i < k; ++i)
            {
                ans += a[s + i * d] * (i + 1);
            }
        }
        else
        {
            ll r = s + d * k;
            ans = S[d][r] - S[d][s] - (s / d) * (pre[d][r] - pre[d][s]);
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}