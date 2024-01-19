#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    set<ll> princes[n + 1];
    ll p, princeId;
    vector<bool> marriedPrincess(n + 1, false);
    vector<bool> marriedPrince(n + 1, false);
    for (ll i = 1; i <= n; ++i)
    {
        cin >> p;
        for (ll j = 0; j < p; ++j)
        {
            cin >> princeId;
            princes[i].insert(princeId);
        }
        for (ll prince : princes[i])
        {
            if (!marriedPrince[prince])
            {
                marriedPrincess[i] = true;
                marriedPrince[prince] = true;
                break;
            }
        }
    }
    ll unmarriedPrince = -1, unmarriedPrincess = -1;
    for (ll i = 1; i <= n; ++i)
    {
        if (!marriedPrince[i])
        {
            unmarriedPrince = i;
        }
        if (!marriedPrincess[i])
        {
            unmarriedPrincess = i;
        }
    }
    if (unmarriedPrince == -1 && unmarriedPrincess == -1)
    {
        cout << "OPTIMAL\n";
    }
    else
    {
        cout << "IMPROVE\n";
        cout << unmarriedPrincess << " " << unmarriedPrince << "\n";
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
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
