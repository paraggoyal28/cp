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
    vector<int> miners, mines;
    int x, y;
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> x >> y;
        if (x == 0)
        {
            miners.push_back(abs(y));
        }
        else if (y == 0)
        {
            mines.push_back(abs(x));
        }
    }
    sort(miners.begin(), miners.end());
    sort(mines.begin(), mines.end());

    double ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += sqrt(miners[i] * miners[i] + mines[i] * mines[i]);
    }

    cout << fixed << setprecision(15);
    cout << ans << endl;
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
