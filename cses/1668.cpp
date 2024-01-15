#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool assignColors(vector<ll> graph[], ll person, vector<ll> &colors, ll color)
{
    colors[person] = color;

    for (ll neigh : graph[person])
    {
        if (!colors[neigh])
        {
            if (!assignColors(graph, neigh, colors, 3 - color))
            {
                return false;
            }
        }
        else if (colors[neigh] != 3 - color)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> friendship[n + 1];
    for (ll i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        friendship[u].push_back(v);
        friendship[v].push_back(u);
    }

    vector<ll> colors(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
    {
        if (!colors[i])
        {
            if (!assignColors(friendship, i, colors, 1))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (ll i = 1; i <= n; ++i)
    {
        cout << colors[i] << " ";
    }
    cout << endl;
    return 0;
}