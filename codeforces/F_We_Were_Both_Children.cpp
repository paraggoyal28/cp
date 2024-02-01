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
    int frogs;
    cin >> frogs;
    map<int, int> hopFreq;
    for (int i = 0; i < frogs; ++i)
    {
        int hopLength;
        cin >> hopLength;
        hopFreq[hopLength] += 1;
    }
    vector<int> trapCount(frogs + 1, 0);
    int maxTrapCount = 0;
    for (auto freq : hopFreq)
    {
        int hopLength = freq.first;
        for (int j = hopLength; j <= frogs; j += hopLength)
        {
            trapCount[j] += freq.second;
        }
    }
    for (int count : trapCount)
    {
        maxTrapCount = max(maxTrapCount, count);
    }
    cout << maxTrapCount << "\n";
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
