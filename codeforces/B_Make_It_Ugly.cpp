// structure of the input will be
//  mmmammmmbmmmmcmmmdmm so on
//
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> nonMajorIdx;
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ll maxElement = arr[0];
    ll prevIdx = -1;
    ll minLength = INT_MAX;
    for (ll i = 0; i < n; ++i)
    {
        if (arr[i] != maxElement)
        {
            nonMajorIdx.push_back(i);
            minLength = min(minLength, i - prevIdx - 1);
            prevIdx = i;
        }
    }
    minLength = min(minLength, n - prevIdx - 1);
    ll ans = minLength == n ? -1 : minLength;
    cout << ans << endl;
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
        solve();
    }
    return 0;
}