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
    vector<int> v(n);
    map<int, vector<int>> occurence;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        occurence[v[i]].push_back(i);
    }
    vector<pair<int, int>> increasingNum;
    for (auto entry : occurence)
    {
        int sz = entry.second.size();
        if (sz == 1)
        {
            increasingNum.push_back({entry.first, 0});
            continue;
        }
        int diff = entry.second[1] - entry.second[0];
        bool isArithmetic = true;
        for (int i = 2; i < sz; ++i)
        {
            if (entry.second[i] - entry.second[i - 1] != diff)
            {
                isArithmetic = false;
                break;
            }
        }
        if (isArithmetic)
        {
            increasingNum.push_back({entry.first, diff});
        }
    }
    cout << increasingNum.size() << endl;
    for (pair<int, int> &values : increasingNum)
    {
        cout << values.first << " " << values.second << endl;
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
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
