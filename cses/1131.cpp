#include <bits/stdc++.h>
#define ll long long int
using namespace std;

pair<ll, ll> bfs(vector<ll> graph[], ll node, ll n)
{
    ll distance = 0, farthestNode = node;
    vector<bool> visited(n + 1, false);
    visited[node] = true;
    queue<ll> q;
    q.push(node);
    while (!q.empty())
    {
        ll sz = q.size();
        for (ll i = 0; i < sz; ++i)
        {
            ll curr = q.front();
            q.pop();

            farthestNode = curr;
            for (ll neigh : graph[curr])
            {
                if (!visited[neigh])
                {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        if (q.size() > 0)
            distance++;
    }
    return {distance, farthestNode};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> graph[n + 1];
    ll u, v;
    for (ll i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    pair<ll, ll> farthest = bfs(graph, 1, n);
    pair<ll, ll> distance = bfs(graph, farthest.second, n);

    cout << distance.first << "\n";
}
