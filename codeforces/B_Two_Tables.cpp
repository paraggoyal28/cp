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
    int W, H;
    cin >> W >> H;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int tableH = y2 - y1;
    int tableW = x2 - x1;
    int ans = INT_MAX;
    // shifted left
    // x2 - dx <= W - w
    // dx >= x2 - (W - w)
    //  shifted right
    // w  <= x1 + dx
    // dx >= w - x1
    // shifted down
    // y2 - dy <= H - h
    // dy >= y2 - (H - h)
    // shifted up
    // y1 + dy >= h
    // dy >= h - y1

    if (tableW + w <= W)
    {
        ans = min(ans, max((int)0, w - x1));
        ans = min(ans, max((int)0, x2 - (W - w)));
    }
    if (tableH + h <= H)
    {
        ans = min(ans, max(0ll, h - y1));
        ans = min(ans, max(0ll, y2 - (H - h)));
    }
    if (ans == INT_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << fixed << setprecision(9);
        cout << double(ans) << "\n";
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
