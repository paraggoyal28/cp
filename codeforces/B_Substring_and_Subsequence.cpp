#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    string a;
    string b;
    cin >> a >> b;
    ll n = a.length();
    ll m = b.length();
    // find longest subset of b that is a subsequence of a
    ll maxCnt = 0;
    for (ll bPtr = 0; bPtr < m; ++bPtr)
    {
        ll cnt = 0;
        ll s = bPtr;
        for (ll aPtr = 0; aPtr < n; ++aPtr)
        {
            if (s < m && b[s] == a[aPtr])
            {
                cnt++;
                s++;
            }
        }
        maxCnt = max(maxCnt, cnt);
    }

    cout << n + m - maxCnt << "\n";
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