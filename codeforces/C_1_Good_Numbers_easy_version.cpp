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

int power(int b, int exp)
{
    if (exp == 0)
        return 1;
    return b * power(b, exp - 1);
}

void solve()
{
    int n;
    cin >> n;
    // 0 to 8
    // 2^8 -> 256
    // 2^9 -> 512
    // 0 0 0
    // 0 0 1
    // 0 1 0
    // 0 1 1
    //
    int totalPerm = (1 << 10);
    for (int i = 0; i < totalPerm; ++i)
    {
        int sum = 0;
        for (int j = 0; j < 10; ++j)
        {
            if (i & (1 << j))
            {
                sum += power(3, j);
            }
        }
        if (n <= sum)
        {
            cout << sum << "\n";
            return;
        }
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
