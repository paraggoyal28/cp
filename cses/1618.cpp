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
    ll ans = 0;
    for (ll i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout << ans << "\n";
}