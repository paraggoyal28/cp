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
    int n, m;
    cin >> n >> m;

    // lower than n/2
    // select m+1
    // upper than n/2
    // select m-1
    // equal to n/2
    // if even then either m-1, m+1
    // if odd then m+1
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    int half = n / 2;
    int ans = 0;
    if (m < half)
    {
        ans = m + 1;
    }
    else if (m > half)
    {
        ans = m - 1;
    }
    else if (n % 2 == 0)
    {
        ans = n / 2;
        if (m == ans)
            ans++;
    }
    else
    {
        ans = n / 2 + 1;
    }
    cout << ans << "\n";
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
