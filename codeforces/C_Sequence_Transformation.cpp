#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    unordered_map<ll, vector<ll>> pos;
    ll v, maxCount = n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> v;
        pos[v].push_back(i);
    }
    for (auto it : pos)
    {
        ll key = it.first;
        ll start = 0;
        ll m = it.second.size();
        ll count = it.second[0] > start ? 1 : 0;
        for (ll i = 1; i < m; ++i)
        {
            if (it.second[i] > it.second[i - 1] + 1)
            {
                count++;
            }
        }
        count += it.second[m - 1] < n - 1 ? 1 : 0;
        maxCount = min(maxCount, count);
    }
    cout << maxCount << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
