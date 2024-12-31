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
    ll maxCurrSum = a[0], maxTotalSum = a[0];
    for (ll i = 1; i < n; ++i)
    {
        maxCurrSum = max(maxCurrSum + a[i], a[i]);
        maxTotalSum = max(maxTotalSum, maxCurrSum);
    }
    cout << maxTotalSum << "\n";
    return 0;
}
