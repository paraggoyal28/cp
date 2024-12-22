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
    ll a;
    set<ll> distinct;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a;
        distinct.insert(a);
    }
    cout << distinct.size() << "\n";
    return 0;
}