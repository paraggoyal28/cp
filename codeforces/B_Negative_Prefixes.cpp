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
    vector<int> num(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }
    vector<int> isLocked(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> isLocked[i];
    }
    vector<int> unlockedNums;
    for (int i = 0; i < n; ++i)
    {
        if (isLocked[i] == 0)
        {
            unlockedNums.push_back(num[i]);
        }
    }
    sort(unlockedNums.begin(), unlockedNums.end());
    int k = unlockedNums.size() - 1;
    for (int i = 0; i < n; ++i)
    {
        if (isLocked[i] == 0)
        {
            cout << unlockedNums[k] << " ";
            k--;
        }
        else
        {
            cout << num[i] << " ";
        }
    }
    // neg > pos
    // pos > neg
    // pos == neg

    //-9 -4 -6 8 9 10
    //    10 9 8 -6 -4 -9
    //          -9
    // -8 -4 -6 -12 -8 -1 0
    // -8 -14 -13 -9 -5 2 0
    // -8 -4  -6 -5 -1 6 0
    // 0 1 -3 3 6
    // -4 1 0 6 3
    // -4 -3 -3 3 6
    // -1 6 16 20 12 11
    //
    cout << "\n";
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
