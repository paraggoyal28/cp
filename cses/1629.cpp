#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> start(n), end(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> start[i] >> end[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minEndTimeFirst;
    for (ll i = 0; i < n; ++i)
    {
        minEndTimeFirst.push({end[i], i});
    }
    ll prevEnd = -1;
    ll movies = 0;
    while (!minEndTimeFirst.empty())
    {
        pair<int, int> curr = minEndTimeFirst.top();
        minEndTimeFirst.pop();
        if (start[curr.second] < prevEnd)
        {
            continue;
        }
        movies++;
        prevEnd = curr.first;
    }
    cout << movies << "\n";
    return 0;
}