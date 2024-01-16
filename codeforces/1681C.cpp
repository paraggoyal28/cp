#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<pair<ll, ll>> solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    vector<pair<ll, ll>> pairs;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < n - i - 1; ++j)
        {
            if (a[j + 1] < a[j] || b[j + 1] < b[j])
            {
                pairs.push_back({j + 1, j + 2});
                swap(a[j + 1], a[j]);
                swap(b[j + 1], b[j]);
            }
        }
    }

    for (ll i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1] || b[i] > b[i + 1])
        {
            vector<pair<ll, ll>> noAns;
            noAns.push_back({-1, -1});
            return noAns;
        }
    }
    return pairs;
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
        vector<pair<ll, ll>> moves = solve();
        if (moves.size() == 1 && moves[0].first == -1)
            cout << "-1\n";
        else
        {
            cout << moves.size() << endl;

            for (pair<ll, ll> &move : moves)
            {
                cout << move.first << " " << move.second << endl;
            }
        }
    }
}