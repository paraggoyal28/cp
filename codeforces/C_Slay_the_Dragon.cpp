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
    vector<int> heros(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> heros[i];
        sum += heros[i];
    }
    sort(heros.begin(), heros.end());
    int dragons;
    cin >> dragons;
    int minCoins;
    for (int i = 0; i < dragons; ++i)
    {
        int defence, attack;
        cin >> defence >> attack;
        minCoins = 0;
        int possibleHero = lower_bound(heros.begin(), heros.end(), defence) - heros.begin();
        if (possibleHero == 0)
        {
            minCoins += max((int)0, attack - sum + heros[possibleHero]);
        }
        else if (possibleHero == n)
        {
            minCoins += defence - heros[possibleHero - 1] + max((int)0, attack - sum + heros[possibleHero - 1]);
        }
        else
        {
            minCoins += min(-heros[possibleHero - 1] + defence + max((int)0, attack - sum + heros[possibleHero - 1]), max((int)0, attack - sum + heros[possibleHero]));
        }
        cout << minCoins << endl;
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
