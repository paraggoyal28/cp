#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000000007

ll damageDone(vector<ll> &time, ll damage)
{
    ll totalDamage = 0;
    ll n = time.size();
    for (ll i = 0; i < n - 1; ++i)
    {
        totalDamage += min(time[i + 1] - time[i], damage);
    }
    totalDamage += damage;
    return totalDamage;
}

void solve()
{
    ll n;
    ll h;
    cin >> n >> h;
    vector<ll> time(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> time[i];
    }
    ll st = 1;
    ll end = h;
    ll res = 1;
    while (st <= end)
    {
        ll mid = st + (end - st) / 2;
        if (damageDone(time, mid) >= h)
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    cout << res << "\n";
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
