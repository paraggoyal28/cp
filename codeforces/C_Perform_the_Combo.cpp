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
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    vector<int> freq(26, 0);
    vector<int> wrongTries(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> wrongTries[i];
    }
    sort(wrongTries.begin(), wrongTries.end());
    for (int i = 0; i < n; ++i)
    {
        int pos = lower_bound(wrongTries.begin(), wrongTries.end(), i + 1) - wrongTries.begin();
        freq[str[i] - 'a'] += m - pos + 1;
    }
    for (int i = 0; i < 26; ++i)
    {
        cout << freq[i] << " ";
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
