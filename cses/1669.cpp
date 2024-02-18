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

vector<int> cycle;

bool dfs(int s, unordered_map<int, vector<int>> &graph, int p, vector<bool> &visited)
{
    visited[s] = 1;
    for (auto i : graph[s])
    {
        cycle.push_back(i);
        if (!visited[i])
        {
            if (dfs(i, graph, s, visited))
                return 1;
        }
        else if (i != p)
        {
            return 1;
        }
        cycle.pop_back();
    }
    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        cycle.push_back(i);
        if (!visited[i] && dfs(i, graph, 0, visited))
        {
            vi ans = {*cycle.rbegin()};
            for (auto j = cycle.rbegin() + 1; j != cycle.rend(); ++j)
            {
                ans.push_back(*j);
                if (*j == *cycle.rbegin())
                    break;
            }
            cout << ans.size() << "\n";
            for (auto i : ans)
                cout << i << " ";
            return;
        }
        cycle.pop_back();
    }
    cout << "IMPOSSIBLE\n";
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
