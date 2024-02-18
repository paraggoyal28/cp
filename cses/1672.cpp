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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, __LONG_LONG_MAX__));
    for (int i = 1; i <= n; ++i)
    {
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w);
        graph[v][u] = min(graph[u][v], w);
    }

    vector<vector<int>> distance(graph);

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (distance[i][k] != __LONG_LONG_MAX__ &&
                    distance[k][j] != __LONG_LONG_MAX__ &&
                    distance[i][j] > distance[i][k] + distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (distance[u][v] != __LONG_LONG_MAX__)
        {
            cout << distance[u][v] << "\n";
        }
        else
        {
            cout << "-1\n";
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
