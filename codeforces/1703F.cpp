#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int

ll findIndex(vector<pair<ll, ll>> &withIndex, ll x)
{
    ll st = 0;
    ll res = -1;
    ll end = withIndex.size() - 1;
    while (st <= end)
    {
        ll mid = st + (end - st) / 2;
        if (withIndex[mid].first > x)
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return res;
}

ll solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> withIndex;
    ll a;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a;
        if (a < i + 1)
        {
            withIndex.push_back({a, i + 1});
        }
    }
    sort(withIndex.begin(), withIndex.end());
    ll pairs = 0;
    ll m = withIndex.size();
    for (ll i = 0; i < m; ++i)
    {
        ll index = findIndex(withIndex, withIndex[i].second);
        if (index != -1)
            pairs += m - index;
    }
    return pairs;
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
        cout << solve() << "\n";
    }
    return 0;
}
