#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    set<ll> a;
    ll num;
    for (ll i = 0; i < n; ++i)
    {
        cin >> num;
        a.insert(num);
    }
    vector<ll> aVec(a.begin(), a.end());
    int left = 0, right = 0;
    int maxLen = 0;
    ll m = aVec.size();
    while (right < m)
    {
        while (left < right && (abs(aVec[left] - aVec[right]) >= n || abs(aVec[left] - aVec[right]) < 1))
        {
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    cout << maxLen << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}