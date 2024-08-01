// current idx I can swim/jump
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    string river;
    cin >> river;
    vector<int> dp(n + 2, -1);
    // dp[i] represents the minimum number of meters that are remaining after swimmed to ith cell.
    dp[0] = k;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (i != n + 1 && river[i - 1] == 'C')
            continue;
        for (int t = 1; t <= m; ++t)
        {
            if (i - t >= 0 && (i - t == 0 || river[i - t - 1] == 'L'))
            {
                dp[i] = max(dp[i], dp[i - t]);
            }
        }
        if (i > 1 && river[i - 2] == 'W')
        {
            dp[i] = max(dp[i], dp[i - 1] - 1);
        }
    }
    if (dp[n + 1] >= 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    // jump till I can jump
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tests = 1;
    cin >> tests;
    while (tests--)
    {
        solve();
    }
    return 0;
}