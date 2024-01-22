#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    vector<ll> stones(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> stones[i];
    }
    bool notOne = true;
    ll operations = 0;
    for (ll i = 1; i < n - 1; ++i)
    {
        if (stones[i] != 1)
        {
            notOne = false;
        }
        if (stones[i] % 2)
        {
            operations += (stones[i] + 1) / 2;
        }
        else
        {
            operations += stones[i] / 2;
        }
    }

    if (n == 3 && stones[1] % 2)
    {
        cout << "-1\n";
    }
    else if (notOne)
    {
        cout << "-1\n";
    }
    else
    {
        cout << operations << endl;
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
