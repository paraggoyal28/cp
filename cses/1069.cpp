#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string seq;
    cin >> seq;
    ll cnt = 1;
    ll maxCnt = 1;
    ll curr = seq[0];
    for (ll i = 1, n = seq.length(); i < n; ++i)
    {
        if (seq[i] == curr)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
            curr = seq[i];
        }
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt << "\n";
    return 0;
}