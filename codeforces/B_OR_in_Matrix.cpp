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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    map<int, int> rowFreq;
    map<int, int> colFreq;
    bool atLeastOne = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                rowFreq[i]++;
                colFreq[j]++;
                atLeastOne = true;
            }
        }
    }
    set<int> oneRow, oneCol;
    for (auto rowPair : rowFreq)
    {
        int rowNum = rowPair.first;
        int freq = rowPair.second;
        if (freq == m)
        {
            oneRow.insert(rowNum);
        }
    }
    for (auto colPair : colFreq)
    {
        int colNum = colPair.first;
        int freq = colPair.second;
        if (freq == n)
        {
            oneCol.insert(colNum);
        }
    }
    if (atLeastOne && (oneCol.size() == 0 || oneRow.size() == 0))
    {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> finalMatrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (oneRow.find(i) != oneRow.end() && oneCol.find(j) != oneCol.end())
            {
                finalMatrix[i][j] = 1;
            }
            else if (matrix[i][j] == 1 && oneRow.find(i) == oneRow.end() && oneCol.find(j) == oneCol.end())
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << finalMatrix[i][j] << " ";
        }
        cout << "\n";
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
