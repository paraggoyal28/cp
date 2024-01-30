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
const int maxn = 32768;

void findNumberOfOperations(int num,
                            unordered_map<int, vector<int>> &graph, vector<int> &distance)
{
    queue<int> q;
    q.push(num);
    distance[num] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neigh : graph[curr])
        {
            if (distance[neigh] == LONG_LONG_MAX)
            {
                distance[neigh] = distance[curr] + 1;
                q.push(neigh);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nonNegNum(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nonNegNum[i];
    }
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < maxn; ++i)
    {
        int num = i;
        int plusOne = (num + 1) % maxn;
        int crossTwo = (num * 2) % maxn;
        graph[plusOne].push_back(num);
        graph[crossTwo].push_back(num);
    }
    vector<int> distance(maxn + 1, LONG_LONG_MAX);
    findNumberOfOperations(0, graph, distance);
    for (int i = 0; i < n; ++i)
    {
        int ans = distance[nonNegNum[i]];
        cout << ans << " ";
    }
    cout << "\n";
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
