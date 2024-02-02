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

int findXor(int curr, int next)
{
    int xorValue = 0;
    for (int i = 31; i >= 0; --i)
    {
        if (!(next & (1 << i)) && (curr & (1 << i)))
        {
            xorValue |= (1 << i);
        }
    }
    return xorValue;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    vector<int> x(n);
    x[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        x[i] = findXor(v[i - 1], v[i]);
        v[i] ^= x[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << x[i] << " ";
    }
    cout << endl;
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
