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

void solve()
{
    int n;
    cin >> n;
    vector<int> pos, neg, a;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            pos.push_back(x);
        }
        else if (x < 0)
        {
            neg.push_back(x);
        }
        else
        {
            if (a.size() < 2)
                a.push_back(x);
        }
    }
    if (pos.size() > 2 || neg.size() > 2)
    {
        cout << "NO\n";
        return;
    }
    for (int i : pos)
        a.push_back(i);
    for (int i : neg)
        a.push_back(i);

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = i + 1; j < a.size(); ++j)
        {
            for (int k = j + 1; k < a.size(); ++k)
            {
                bool ok = false;
                for (int l = 0; l < a.size(); ++l)
                {
                    if (a[i] + a[j] + a[k] == a[l])
                    {
                        ok = true;
                    }
                }
                if (!ok)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
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