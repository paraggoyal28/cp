#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long> pref;
    pref.push_back(0);
    vector<int> prefmax;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        pref.push_back(pref.back() + x);
        if (i == 0)
        {
            prefmax.push_back(x);
        }
        else
        {
            prefmax.push_back(max(x, prefmax.back()));
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int k;
        cin >> k;
        int ind = upper_bound(prefmax.begin(), prefmax.end(), k) - prefmax.begin();
        cout << pref[ind] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}