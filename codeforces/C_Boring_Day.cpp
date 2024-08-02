#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> nums(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    ll left = 0, right = 0;
    ll sum = 0;
    ll rounds = 0;
    while (left < n)
    {
        while (right < n && sum < l)
        {
            sum += nums[right++];
        }
        if (sum >= l && sum <= r)
        {
            sum = 0;
            rounds++;
            left = right;
        }
        else
        {
            sum -= nums[left++];
        }
    }

    cout << rounds << "\n";
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