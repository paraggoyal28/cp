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

bool allEquals(vector<int> &v)
{
    int first = v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i)
    {
        if (v[i] != first)
        {
            return false;
        }
    }
    return true;
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
    if (allEquals(v))
    {
        cout << "1\n";
    }
    else
    {
        int peaks = 0, troughs = 0;
        int itr = 0;
        while (itr < n - 1)
        {
            while (itr < n - 1 && v[itr] == v[itr + 1])
            {
                itr++;
            }
            if (itr < n - 1 && v[itr] < v[itr + 1])
            {
                troughs++;
                while (itr < n - 1 && v[itr] <= v[itr + 1])
                {
                    itr++;
                }
            }
            if (itr < n - 1 && v[itr] > v[itr + 1])
            {
                peaks++;
                while (itr < n - 1 && v[itr] >= v[itr + 1])
                {
                    itr++;
                }
            }
        }
        cout << peaks + troughs + 1 << "\n";
    }
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
