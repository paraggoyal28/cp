#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    map<ll, ll> pos;
    for (ll i = 0; i < n; ++i)
    {
        if (pos.find(x - arr[i]) != pos.end())
        {
            cout << pos[x - arr[i]] << " " << i + 1 << "\n";
            return 0;
        }
        pos[arr[i]] = i + 1;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}