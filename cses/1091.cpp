#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    map<ll, ll> price;
    ll p;
    vector<ll> maxPrice(m);

    for (ll i = 0; i < n; ++i)
    {
        cin >> p;
        price[p]++;
    }
    for (ll &p : maxPrice)
    {
        cin >> p;
    }

    // assign lowest possible price to each person

    for (ll mp : maxPrice)
    {
        auto maxAllowedPrice = price.lower_bound(mp);
        if (price.empty())
        {
            cout << "-1\n";
            continue;
        }
        if (maxAllowedPrice == price.end())
        {
            maxAllowedPrice--;
        }
        if (maxAllowedPrice->first > mp && maxAllowedPrice == price.begin())
        {
            cout << "-1\n";
            continue;
        }
        if (maxAllowedPrice->first > mp)
        {
            maxAllowedPrice--;
        }
        cout << maxAllowedPrice->first << "\n";
        if (maxAllowedPrice->second == 1)
        {
            price.erase(maxAllowedPrice->first);
        }
        else
        {
            price[maxAllowedPrice->first]--;
        }
    }
    return 0;
}