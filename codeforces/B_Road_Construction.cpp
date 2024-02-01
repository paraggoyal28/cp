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
    int n, m;
    cin >> n >> m;
    vector<bool> cannotBuildRoad(n + 1, false);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        cannotBuildRoad[u] = true;
        cannotBuildRoad[v] = true;
    }
    int root;
    for (int i = 1; i <= n; ++i)
    {
        if (!cannotBuildRoad[i])
        {
            root = i;
            break;
        }
    }

    cout << n - 1 << "\n";
    for (int i = 1; i <= n; ++i)
    {
        if (i != root)
        {
            cout << i << " " << root << "\n";
        }
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
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
