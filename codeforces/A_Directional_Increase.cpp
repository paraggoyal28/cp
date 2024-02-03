#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define back(v) v.rbegin(), v.rend()
#define nl "\n"
#define yes cout << "YES" << nl;
#define no cout << "NO" << nl;
#define deb(a) cerr << #a << "=" << (a) << nl;
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;
#define mod 1000000007
const int oo = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> ps(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    if (ps[n] != 0)
    {
        cout << "No\n";
        return;
    }
    bool ok = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (ps[i] < 0)
            ok = 0;
    }
    bool visited_zero = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ps[i] == 0)
            visited_zero = 1;
        else if (visited_zero)
            ok = 0;
    }
    if (ok)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
signed main()
{
    FastIO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
