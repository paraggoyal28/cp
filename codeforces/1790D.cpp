#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve()
{
    ll n;
    cin >> n;
    vector<ll> sizes(n);
    map<ll, ll> cnt;
    set<ll> b;
    for (ll i = 0; i < n; ++i)
    {
        cin >> sizes[i];
        cnt[sizes[i]]++;
        b.insert(sizes[i]);
        b.insert(sizes[i] + 1);
    }

    ll last = 0;
    ll res = 0;
    for (auto x : b)
    {
        ll c = cnt[x];
        res += max(0LL, c - last);
        last = c;
    }

    return res;
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
        cout << solve() << endl;
    }
    return 0;
}