#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> pos(n, 0);
        int p;
        for (int i = 0; i < m; ++i)
        {
            cin >> p;
            pos[p - 1] = 1;
        }

        for (int i = 0; i < n; ++i)
        {
            if (pos[i] == 0)
                continue;
            int j = i;
            while (j < n && pos[j])
                j++;
            sort(a.begin() + i, a.begin() + j + 1);
            i = j;
        }

        bool ok = true;
        for (int i = 0; i < n - 1; ++i)
        {
            ok &= a[i] <= a[i + 1];
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}