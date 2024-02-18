#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define mii map<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
#define ld long double
#define pb push_back
#define vc vector
#define S second
#define F first
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

const int N = 100005;
int vis[N];
int dis1[N], dis2[N];
void dij(int s, int dis[], vii adj[])
{
    priority_queue<pii> q;
    rep(i, 1, N) dis[i] = oo;
    dis[s] = 0;
    q.push({0, s});
    memset(vis, 0, sizeof(vis));
    while (!q.empty())
    {
        int a = q.top().S;
        q.pop();
        if (vis[a])
            continue;
        vis[a] = 1;
        for (auto [b, w] : adj[a])
        {
            if (dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vii adj1[n + 1], adj2[n + 1];
    vc<tuple<int, int, int>> e;
    rep(i, 0, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        e.pb({a, b, w});
        adj1[a].pb({b, w});
        adj2[b].pb({a, w});
    }
    dij(1, dis1, adj1);
    dij(n, dis2, adj2);
    int mn = oo;
    for (auto [a, b, w] : e)
    {
        mn = min(mn, dis1[a] + dis2[b] + w / 2);
    }
    cout << mn << endl;
}
signed main()
{
    FastIO;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
