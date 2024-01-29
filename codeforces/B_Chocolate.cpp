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
    int n;
    cin >> n;
    vector<int> pieces(n);
    vector<int> onePos;
    for (int i = 0; i < n; ++i)
    {
        cin >> pieces[i];
        if (pieces[i] == 1)
        {
            onePos.push_back(i);
        }
    }
    int ways = 1;
    int m = onePos.size();
    if (m == 0)
    {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < m - 1; ++i)
    {
        ways *= onePos[i + 1] - onePos[i];
    }
    cout << ways << endl;
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
