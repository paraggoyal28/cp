// a for rest I cannot select a number d*a
// a b c, b%a != 0

// 4 5 6 7 8 9

// continguous sequeunce a, a+1, a+N-1, if n > a
// choose a > n
// 10^5+10^5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    ll a = n;
    for (ll i = 0; i < n; ++i)
    {
        cout << a + i << " ";
    }
    cout << "\n";
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
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
