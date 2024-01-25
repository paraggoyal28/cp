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
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> permutation[i];
    }
    int st = 0;
    int end = n - 1;
    int minimum = 1;
    int maximum = n;
    while (st < end)
    {
        if (permutation[st] == minimum)
        {
            st++;
            minimum++;
        }
        else if (permutation[st] == maximum)
        {
            maximum--;
            st++;
        }
        else if (permutation[end] == minimum)
        {
            minimum++;
            end--;
        }
        else if (permutation[end] == maximum)
        {
            maximum--;
            end--;
        }
        else
        {
            cout << st + 1 << " " << end + 1 << "\n";
            return;
        }
    }
    cout << "-1\n";
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
