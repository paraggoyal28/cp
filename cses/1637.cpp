#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll calculateMin(vector<ll> &dp, ll num)
{
    ll digit;
    ll originalNum = num;
    ll minCost = INT_MAX;
    while (num > 0)
    {
        digit = num % 10;
        if (digit != 0)
            minCost = min(minCost, dp[originalNum - digit]);
        num /= 10;
    }
    return minCost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 1);
    for (ll i = 10; i <= n; ++i)
    {
        dp[i] = 1 + calculateMin(dp, i);
    }
    cout << dp[n] << "\n";
    return 0;
}