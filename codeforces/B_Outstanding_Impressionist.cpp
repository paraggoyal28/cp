#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    vector<int> prefixSum(2 * n + 1, 0);
    map<ll, ll> cnt;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first == a[i].second)
        {
            prefixSum[a[i].first] = 1;
            cnt[a[i].first] += 1;
        }
    }
    for (ll i = 1; i <= 2 * n; ++i)
    {
        prefixSum[i] += prefixSum[i - 1];
    }
    for (ll i = 0; i < n; ++i)
    {
        if (a[i].first == a[i].second)
        {
            if (cnt[a[i].first] > 1)
            {
                cout << "0";
            }
            else
            {
                cout << "1";
            }
        }
        else
        {
            int subarraySum = prefixSum[a[i].second] - prefixSum[a[i].first - 1];
            if (subarraySum == a[i].second - a[i].first + 1)
            {
                cout << "0";
            }
            else
            {
                cout << "1";
            }
        }
    }
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
        cout << "\n";
    }
    return 0;
}