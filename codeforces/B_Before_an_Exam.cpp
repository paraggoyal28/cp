#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int d, sumTime;
    cin >> d >> sumTime;
    vector<pair<pair<int, int>, int>> time(d);
    vector<int> res(d);
    ll sum = 0;
    for (ll i = 0; i < d; ++i)
    {
        cin >> time[i].first.first >> time[i].first.second;
        time[i].second = i;
        res[i] = time[i].first.first;
        sum += time[i].first.first;
    }
    sort(time.begin(), time.end());
    int diff = sumTime - sum;

    for (int i = 0; i < d && diff > 0; ++i)
    {
        pair<pair<int, int>, int> curr = time[i];
        if (diff + curr.first.first >= curr.first.second)
        {
            diff += curr.first.first;
            diff -= curr.first.second;
            res[curr.second] = curr.first.second;
        }
        else
        {
            res[curr.second] = diff + curr.first.first;
            diff = 0;
        }
    }

    if (diff == 0)
    {
        cout << "YES\n";
        for (ll i = 0; i < d; ++i)
        {
            cout << res[i] << " ";
        }
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
