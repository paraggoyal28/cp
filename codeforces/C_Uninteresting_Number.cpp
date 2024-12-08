#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    string s;
    cin >> s;

    ll cntTwos = 0, cntThrees = 0;
    ll sum = 0;
    for (char &ch : s)
    {
        if (ch == '2')
        {
            cntTwos++;
        }
        else if (ch == '3')
        {
            cntThrees++;
        }
        sum = (sum + (ch - '0')) % 9;
    }

    cntTwos = min(cntTwos, 8LL);
    cntThrees = min(cntThrees, 8LL);

    for (int i = 0; i <= cntTwos; ++i)
    {
        for (int j = 0; j <= cntThrees; ++j)
        {
            if (((sum + 2 * i + 6 * j) % 9) == 0)
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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