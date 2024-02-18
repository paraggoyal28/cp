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
    unordered_map<int, vector<pair<int, int>>> graph;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> distance(n + 1, __LONG_LONG_MAX__);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[1] = 0;
    vector<bool> visited(n + 1, false);
    pq.push({0, 1});
    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();

        int node = curr.second;
        if (visited[node])
            continue;
        visited[node] = 1;
        for (pair<int, int> neighbor : graph[node])
        {
            if (distance[neighbor.first] > distance[node] + neighbor.second)
            {
                distance[neighbor.first] = distance[node] + neighbor.second;
                pq.push({distance[neighbor.first], neighbor.first});
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
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
