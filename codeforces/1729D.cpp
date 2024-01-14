#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int

ll solve()
{
    ll n;
    cin >> n;
    vector<ll> spend(n), budget(n);
    vector<ll> diff(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> spend[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        cin >> budget[i];
        diff[i] = budget[i] - spend[i];
    }
    sort(diff.begin(), diff.end());
    ll start = 0, end = n - 1;
    ll days = 0;
    while (start < end)
    {
        if (diff[start] + diff[end] < 0)
        {
            start += 1;
        }
        else
        {
            days += 1;
            start += 1;
            end -= 1;
        }
    }

    return days;
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
        cout << solve() << "\n";
    }
    return 0;
}