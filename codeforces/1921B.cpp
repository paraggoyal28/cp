#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve()
{
    ll n;
    cin >> n;
    vector<char> initial(n);
    vector<char> final(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> initial[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        cin >> final[i];
    }
    ll inE = 0, fiE = 0;
    for (ll i = 0; i < n; ++i)
    {
        if (initial[i] == final[i])
            continue;
        else if (initial[i] == '1')
            inE += 1;
        else
            fiE += 1;
    }
    return max(fiE, inE);
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
        cout << solve() << endl;
    }
    return 0;
}