#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isCorner(ll r, ll c, ll rows, ll cols)
{
    return r == 0 && c == 0 || r == rows - 1 && c == 0 || r == 0 && c == cols - 1 || r == rows - 1 && c == cols - 1;
}

bool isBorder(ll r, ll c, ll rows, ll cols)
{
    return r == 0 || c == 0 || r == rows - 1 || c == cols - 1;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> matrix(n, vector<ll>(m, 0));
    vector<vector<ll>> finalMatrix(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            if (isCorner(i, j, n, m))
            {
                finalMatrix[i][j] = 2;
            }
            else if (isBorder(i, j, n, m))
            {
                finalMatrix[i][j] = 3;
            }
            else
            {
                finalMatrix[i][j] = 4;
            }
            if (matrix[i][j] > finalMatrix[i][j])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            cout << finalMatrix[i][j] << " ";
        }
        cout << "\n";
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
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
