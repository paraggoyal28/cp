#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll MOD = 1e9 + 7;
    vector<vector<char>> mat(n, vector<char>(n, '.'));
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = mat[0][0] == '.';

    for (ll i = 1; i < n; ++i)
    {
        dp[0][i] = mat[0][i] == '*' ? 0 : dp[0][i - 1];
        dp[i][0] = mat[i][0] == '*' ? 0 : dp[i - 1][0];
    }

    for (ll i = 1; i < n; ++i)
    {
        for (ll j = 1; j < n; ++j)
        {
            if (mat[i][j] != '*')
            {
                dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}