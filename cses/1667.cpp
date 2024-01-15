#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> connections[n + 1];
    for (ll i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        connections[u].push_back(v);
        connections[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    visited[1] = true;
    queue<ll> route;
    vector<ll> parent(n + 1, -1);
    route.push(1);
    while (!route.empty())
    {
        ll curr = route.front();
        route.pop();

        if (curr == n)
        {
            break;
        }

        for (ll neigh : connections[curr])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                parent[neigh] = curr;
                route.push(neigh);
            }
        }
    }

    ll end = n;
    vector<ll> path;
    while (end != -1)
    {
        path.push_back(end);
        end = parent[end];
    }
    reverse(path.begin(), path.end());
    if (path[0] != 1 || path[path.size() - 1] != n)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << path.size() << "\n";
        for (ll comp : path)
        {
            cout << comp << " ";
        }
        cout << "\n";
    }
    return 0;
}