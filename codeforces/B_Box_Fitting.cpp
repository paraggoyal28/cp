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
    int n, box_width, w;
    cin >> n >> box_width;

    vector<int> counts(20);
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        counts[log2(w)]++;
    }

    int height = 1, space_left = box_width;

    for (int iter = 0; iter < n; iter++)
    {
        int largest = -1;

        for (int size = 19; size >= 0; size--)
        {
            if (counts[size] and (1 << size) <= space_left)
            {
                largest = size;
                break;
            }
        }

        if (largest == -1)
        {
            space_left = box_width;
            height++;
            for (int size = 19; size >= 0; size--)
            {
                if (counts[size] and (1 << size) <= space_left)
                {
                    largest = size;
                    break;
                }
            }
        }

        counts[largest] -= 1;
        space_left -= 1 << largest;
    }

    cout << height << endl;
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
