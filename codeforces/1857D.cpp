#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; ++i)
        {
            cin >> b[i];
        }
        ll mx = INT_MIN;
        for (ll i = 0; i < n; ++i)
        {
            mx = max(mx, a[i] - b[i]);
        }
        ll c = 0;
        for (ll i = 0; i < n; ++i)
        {
            c += (a[i] - b[i] == mx);
        }
        cout << c << endl;
        for (ll i = 0; i < n; ++i)
        {
            if (a[i] - b[i] == mx)
                cout << i + 1 << " ";
        }
        cout << endl;
    }
}