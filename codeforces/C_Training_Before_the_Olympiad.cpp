#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    ll oddCnt;
    vector<ll> ans;
    ans.push_back(a[0]);
    oddCnt = a[0] % 2 ? 1 : 0;
    ll prefixSum = a[0];
    for (ll i = 1; i < n; ++i)
    {
        prefixSum += a[i];
        if (a[i] % 2)
        {
            oddCnt++;
        }
        if (oddCnt % 3 == 0)
        {
            ans.push_back(prefixSum - oddCnt / 3);
        }
        else if (oddCnt % 3 == 1)
        {
            ans.push_back(prefixSum - oddCnt / 3 - 1);
        }
        else
        {
            ans.push_back(prefixSum - oddCnt / 3);
        }
    }

    for (ll num : ans)
    {
        cout << num << " ";
    }
    cout << "\n";
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