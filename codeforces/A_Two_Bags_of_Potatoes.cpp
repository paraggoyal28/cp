#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll y, k, n;
    cin >> y >> k >> n;
    ll maxX = n - y;
    ll rem = y % k;
    ll start = k - y % k;
    if (maxX <= 0 || (start + y) > n)
    {
        cout << "-1\n";
        return;
    }
    for (ll i = 0; start <= maxX; ++i)
    {
        cout << start << " ";
        start += k;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
