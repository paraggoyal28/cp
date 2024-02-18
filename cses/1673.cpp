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

int dis[2505];
const int M = 1e16;
vi adj[2505], adj2[2505];
bool vis[2505], vis2[2505];
void dfs(int s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto i : adj[s])
        dfs(i);
}
void dfs2(int s)
{
    if (vis2[s])
        return;
    vis2[s] = 1;
    for (auto i : adj2[s])
        dfs2(i);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, n + 1) dis[i] = M;
    dis[1] = 0;
    vector<tuple<int, int, int>> e;
    rep(i, 0, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        e.pb({a, b, -w});
        adj[a].pb(b), adj2[b].pb(a);
    }
    dfs(1), dfs2(n);
    rep(i, 0, n)
    {
        for (auto [a, b, w] : e)
        {
            if (dis[b] > dis[a] + w)
            {
                dis[b] = dis[a] + w;
                if (i == n - 1 && vis[b] && vis2[b])
                {
                    cout << "-1\n";
                    return;
                }
            }
        }
    }
    cout << -dis[n] << "\n";
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
