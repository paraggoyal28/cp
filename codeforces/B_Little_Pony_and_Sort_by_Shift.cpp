#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isSorted(vector<ll> &a, ll start, ll end)
{
    for (ll i = start; i < end; ++i)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int minIdx = -1;
    bool found = false;
    for (ll i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            if (!found)
            {
                minIdx = i;
                found = true;
            }
            else
            {
                cout << "-1\n";
                return;
            }
        }
    }

    if (minIdx == -1)
    {
        cout << "0\n";
        return;
    }
    if (isSorted(a, minIdx + 1, n - 1) && isSorted(a, 0, minIdx) && a[n - 1] <= a[0])
    {

        cout << n - minIdx - 1 << endl;
    }
    else
    {
        cout << "-1\n";
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
