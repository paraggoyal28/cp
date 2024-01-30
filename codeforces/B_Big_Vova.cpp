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
    vector<int> posNum(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> posNum[i];
    }
    sort(posNum.begin(), posNum.end());

    int maxGcd = 0, maxGcdIdx = n - 1;
    int finalGcd = posNum[n - 1];
    for (int j = n - 1; j > 0; --j)
    {
        maxGcd = 0;
        maxGcdIdx = j - 1;
        for (int i = j - 1; i >= 0; --i)
        {
            int gcd = __gcd(posNum[i], finalGcd);
            if (gcd > maxGcd)
            {
                maxGcd = gcd;
                maxGcdIdx = i;
            }
        }
        finalGcd = maxGcd;
        if (maxGcd == 1)
        {
            break;
        }
        swap(posNum[maxGcdIdx], posNum[j - 1]);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        cout << posNum[i] << " ";
    }
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
