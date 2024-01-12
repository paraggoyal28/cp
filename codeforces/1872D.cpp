#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll findGcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }

    return findGcd(y, x % y);
}

ll findLcm(ll x, ll y)
{
    return (x * y) / findGcd(x, y);
}

ll rangeSum(ll l, ll r)
{
    if (l > r)
        return 0;

    return ((r + l) * (r - l + 1)) / 2;
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
        ll n, x, y;
        cin >> n >> x >> y;
        ll lcm = findLcm(x, y);
        ll plus = n / x - n / lcm;
        ll minus = n / y - n / lcm;
        ll ans = rangeSum(n - plus + 1, n) - rangeSum(1, minus);
        cout << ans << endl;
    }
}