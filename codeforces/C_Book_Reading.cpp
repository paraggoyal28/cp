#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mod 1000000007
void solve()
{
    ll n, m;
    cin >> n >> m;
    int prefix[10][11];
    memset(prefix, 0, sizeof(prefix));
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            prefix[i][j] = prefix[i][j - 1] + (i * j) % 10;
        }
    }

    ll rem = (n % (m * 10)) / (m);
    ll q = n / (m * 10);

    ll ans = q * prefix[m % 10][10] + prefix[m % 10][rem];

    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
