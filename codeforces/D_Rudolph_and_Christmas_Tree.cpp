#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
void solve()
{
    ld n, d, h;
    cin >> n >> d >> h;
    vector<ld> y(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> y[i];
    }
    ld area = 0;
    for (ll i = 0; i < n - 1; ++i)
    {
        ld diff = y[i + 1] - y[i];
        if (diff >= h)
        {
            area += (double)(d * h) / (2.0);
        }
        else
        {
            ld tantheta = (2 * h) / d;
            ld secondbase = d - ((2.0 * diff) / tantheta);
            area += ((secondbase + d) * 1.0 * diff) / 2.0;
        }
    }
    area += (d * h) / (2.0);
    cout << fixed << setprecision(7);
    cout << area << endl;
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
