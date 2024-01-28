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

void dfs(vector<int> tree[], int node, vector<bool> &visited, vector<int> &apples)
{
    visited[node] = true;

    int appleCount = 0;
    for (int neigh : tree[node])
    {
        if (!visited[neigh])
        {
            dfs(tree, neigh, visited, apples);
            appleCount += apples[neigh];
        }
    }
    apples[node] = max(1LL, appleCount);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> tree[n + 1];
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> apples(n + 1, 0);
    vector<bool> visited(n + 1, false);
    dfs(tree, 1, visited, apples);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << apples[l] * apples[r] << "\n";
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
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
