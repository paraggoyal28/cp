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

void dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &color, int clr)
{
    color[node] = clr;

    for (int neigh : graph[node])
    {
        if (color[neigh] == 0)
        {
            dfs(neigh, graph, color, 3 - clr);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, vector<int>> graph;
    int u, v;

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> color(n, 0);
    dfs(1, graph, color, 1);
    int partOne = 0, partTwo = 0;
    for (int i = 0; i < n; ++i)
    {
        if (color[i] == 1)
        {
            partOne++;
        }
        else
        {
            partTwo++;
        }
    }
    int maxPossibleEdges = partOne * partTwo;
    cout << maxPossibleEdges - n + 1 << endl;
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
