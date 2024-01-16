#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    ll diff = 0;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll j = 0, k = m - 1;
    ll i = 0, l = n - 1;
    while (i <= l)
    {
        ll iMax = max(abs(a[i] - b[j]), abs(a[i] - b[k]));
        ll lMax = max(abs(a[l] - b[j]), abs(a[l] - b[k]));
        if (iMax >= lMax)
        {
            if (abs(a[i] - b[j]) >= abs(a[i] - b[k]))
            {
                diff += abs(a[i] - b[j]);
                j++;
            }
            else
            {
                diff += abs(a[i] - b[k]);
                k--;
            }
            i++;
        }
        else
        {
            if (abs(a[l] - b[j]) >= abs(a[l] - b[k]))
            {
                diff += abs(a[l] - b[j]);
                j++;
            }
            else
            {
                diff += abs(a[l] - b[k]);
                k--;
            }
            l--;
        }
    }
    return diff;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}