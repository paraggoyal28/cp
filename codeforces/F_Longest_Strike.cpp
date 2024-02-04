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
    int n, k;
    cin >> n >> k;
    map<int, int> freq;
    set<int> freqgeK;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        freq[num]++;
        if (freq[num] >= k)
        {
            freqgeK.insert(num);
        }
    }
    int maxCount = 0;
    int start = -1;
    for (int it : freqgeK)
    {
        if (freqgeK.find(it - 1) == freqgeK.end())
        {
            int tmp = it;
            int count = 0;
            while (freqgeK.find(tmp) != freqgeK.end())
            {
                tmp++;
                count++;
            }
            if (maxCount < count)
            {
                maxCount = count;
                start = it;
            }
        }
    }
    if (start == -1)
        cout << "-1\n";
    else
        cout << start << " " << start + maxCount - 1 << "\n";
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
