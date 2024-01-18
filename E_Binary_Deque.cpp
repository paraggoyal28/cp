#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    ll initialSum = 0;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
        initialSum += a[i];
    }
    if (s > initialSum)
    {
        cout << "-1\n";
        return;
    }
    // max window of sum s
    ll r = 0, l = 0, sum = 0;
    ll maxWindow = 0;
    while (r < n)
    {
        sum += a[r];
        while (l < r && sum > s)
        {
            sum -= a[l];
            l += 1;
        }
        if (sum == s)
        {
            maxWindow = max(maxWindow, r - l + 1);
        }
        r += 1;
    }
    cout << n - maxWindow << endl;
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
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
