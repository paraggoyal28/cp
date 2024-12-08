#include <iostream>
#include <set>

using namespace std;
const int N = 3e5 + 10;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = '0' + s; // only for making the iteration start from 1

    set<int> a;
    for (int i = 1; i <= n; ++i)
    {
        a.insert(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        int mx = *begin(a), k = 0, cnt = 0;
        for (int j : a)
        { // check first 10 elements
            if (cnt == 10)
                break;
            if (s[mx] - k < s[j] - cnt)
            {
                mx = j, k = cnt;
            }
            cnt++;
        }
        cout << char(s[mx] - k);
        a.erase(mx);
    }
    cout << "\n";
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}