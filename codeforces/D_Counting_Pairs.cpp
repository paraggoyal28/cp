#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll findLeftValidIdx(vector<ll> &a, ll sum, ll start, ll end, ll x, ll y)
{
    ll idx = start - 1;
    ll res = -1;
    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (sum - a[idx] - a[mid] >= x && sum - a[idx] - a[mid] <= y)
        {
            res = mid;
            end = mid - 1;
        }
        else if (sum - a[idx] - a[mid] < x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

ll findRightValidIdx(vector<ll> &a, ll sum, ll start, ll end, ll x, ll y)
{
    ll idx = start - 1;
    ll res = -1;
    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (sum - a[idx] - a[mid] >= x && sum - a[idx] - a[mid] <= y)
        {
            res = mid;
            start = mid + 1;
        }
        else if (sum - a[idx] - a[mid] < x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int idx = 0; idx < n; ++idx)
    {
        int leftValidIdx = findLeftValidIdx(a, sum, idx + 1, n - 1, x, y);
        int rightValidIdx = findRightValidIdx(a, sum, idx + 1, n - 1, x, y);
        if (leftValidIdx == -1 || rightValidIdx == -1)
            continue;
        ans += rightValidIdx - leftValidIdx + 1;
    }
    cout << ans << "\n";
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
        solve();
    }
    return 0;
}