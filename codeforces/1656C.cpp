#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int

bool solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool isOnePresent = false;
    bool isConsecutive = false;
    if (a[0] == 1)
        isOnePresent = true;
    for (ll i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1] + 1)
            isConsecutive = true;
        if (a[i] == 1)
            isOnePresent = true;
    }

    return !isOnePresent || !isConsecutive;
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
        if (solve())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}