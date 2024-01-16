#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> badges(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> badges[i];
    }
    sort(badges.begin(), badges.end());
    ll count = 0;
    for (ll i = 1; i < n; ++i)
    {
        if (badges[i] <= badges[i - 1])
        {
            count += badges[i - 1] + 1 - badges[i];
            badges[i] = badges[i - 1] + 1;
        }
    }
    cout << count << "\n";
}