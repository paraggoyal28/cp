#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll median = 0, ans = 0;
    if (n % 2)
    {
        median = a[n / 2];
    }
    else
    {
        median = (a[n / 2] + a[n / 2 - 1]) / 2;
    }
    for (ll i = 0; i < n; ++i)
    {
        ans += abs(a[i] - median);
    }
    cout << ans << "\n";
    return 0;
}