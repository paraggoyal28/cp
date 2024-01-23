#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
ll solve()
{
    ll x;
    cin >> x;

    ll steps = 0;
    while (steps * (steps + 1) < 2 * x)
        steps++;

    if (steps * (steps + 1) / 2 == x + 1)
        steps++;
    return steps;
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
        cout << solve() << endl;
    }
    return 0;
}
