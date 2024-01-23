#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> ans;
    for (ll d = 1; d <= y - x; ++d)
    {
        if ((y - x) % d)
            continue;
        bool foundx = false;
        vector<ll> res;
        ll cur = y;
        ll need = n;
        while (cur >= 1 && need > 0)
        {
            res.push_back(cur);
            foundx |= cur == x;
            --need;
            cur -= d;
        }
        cur = y;
        while (need > 0)
        {
            cur += d;
            res.push_back(cur);
            --need;
        }
        sort(res.begin(), res.end());
        if (need == 0 && foundx)
        {
            if (ans.empty() || ans.back() > res.back())
            {
                ans = res;
            }
        }
    }
    assert(!ans.empty());
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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
