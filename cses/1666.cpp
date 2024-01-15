#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(vector<ll> graph[], ll city, vector<bool> &visited)
{
    visited[city] = true;

    for (ll neigh : graph[city])
    {
        if (!visited[neigh])
        {
            dfs(graph, neigh, visited);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> graph[n + 1];
    for (ll i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    vector<ll> roads;
    for (ll i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited);
            roads.push_back(i);
        }
    }
    cout << roads.size() - 1 << endl;
    ll sz = roads.size();
    for (ll i = 0; i < sz - 1; ++i)
    {
        cout << roads[i] << " " << roads[i + 1] << endl;
    }
    return 0;
}