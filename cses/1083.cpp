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
    ll targetSum = (n * (n + 1)) / 2;
    ll a;
    ll actualSum = 0;
    for (ll i = 0; i < n - 1; ++i)
    {
        cin >> a;
        actualSum += a;
    }
    cout << targetSum - actualSum << "\n";
    return 0;
}