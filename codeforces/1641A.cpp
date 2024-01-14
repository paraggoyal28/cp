#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    map<ll, ll> freq;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
        freq[a[i]] += 1;
    }
    ll s = 0, e = 1;
    ll add = 0;
    for (auto it : freq)
    {
        if (freq[it.first] > 0 && freq[it.first * x] > 0)
        {
            int minFreq = min(freq[it.first], freq[it.first * x]);
            freq[it.first] -= minFreq;
            freq[it.first * x] -= minFreq;
        }
    }
    for (auto it : freq)
    {
        add += it.second;
    }

    cout << add << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tests;
    cin >> tests;
    while (tests--)
    {
        solve();
    }
    return 0;
}