#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    char lastChar = 'a';
    ll lastPos = 0;
    unordered_map<char, vector<ll>> pos;
    set<char> sortedChar;
    for (ll i = 0; i < n; ++i)
    {
        pos[str[i]].push_back(i);
        sortedChar.insert(str[i]);
    }
    vector<char> sortedVec(sortedChar.begin(), sortedChar.end());

    for (ll i = 0, m = sortedVec.size(); i < m && k > 0; ++i)
    {
        char ch = sortedVec[i];
        if (k > pos[ch].size())
        {
            k -= pos[ch].size();
        }
        else if (k < pos[ch].size())
        {
            lastChar = ch;
            lastPos = pos[ch][k];
            k = 0;
        }
        else
        {
            if (i < m - 1)
            {
                lastChar = sortedVec[i + 1];
                lastPos = pos[sortedVec[i + 1]][0];
            }
            else
            {
                cout << "\n";
                return;
            }
            k = 0;
        }
    }
    string res = "";
    for (ll i = 0; i < n; ++i)
    {
        if (str[i] > lastChar || str[i] == lastChar && i >= lastPos)
        {
            res += str[i];
        }
    }
    cout << res << "\n";
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
