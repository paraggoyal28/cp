#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    ll right = points[0].first;
    ll top = points[0].second;
    string ans;
    ll sR = 0;
    ll sC = 0;
    while (sR < right)
    {
        ans += 'R';
        sR += 1;
    }
    while (sC < top)
    {
        ans += 'U';
        sC += 1;
    }
    for (ll i = 1; i < n; ++i)
    {
        if (points[i - 1].second > points[i].second)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            while (sR < points[i].first)
            {
                ans += 'R';
                sR += 1;
            }
            while (sC < points[i].second)
            {
                ans += 'U';
                sC += 1;
            }
        }
    }
    cout << "YES" << endl;
    cout << ans << endl;
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