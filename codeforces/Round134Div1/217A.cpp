#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define ll long long int

bool canDrift(pair<ll, ll> &coordA, pair<ll, ll> &coordB)
{
    return coordA.first == coordB.first || coordA.second == coordB.second;
}

void dfs(unordered_map<ll, vector<ll>> &graph, ll snow_drift, vector<bool> &visited)
{
    visited[snow_drift] = true;

    for (ll neighDrift : graph[snow_drift])
    {
        if (!visited[neighDrift])
        {
            dfs(graph, neighDrift, visited);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll snow_drifts;
    cin >> snow_drifts;
    unordered_map<ll, vector<ll>> graph;

    vector<pair<ll, ll>> coordinates(snow_drifts);
    for (ll i = 0; i < snow_drifts; ++i)
    {
        cin >> coordinates[i].first >> coordinates[i].second;
    }

    for (ll i = 0; i < snow_drifts; ++i)
    {
        for (ll j = i + 1; j < snow_drifts; ++j)
        {
            if (canDrift(coordinates[i], coordinates[j]))
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> visited(snow_drifts, false);

    int components = 0;
    for (ll i = 0; i < snow_drifts; ++i)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited);
            components += 1;
        }
    }

    cout << components - 1 << endl;
    return 0;
}
