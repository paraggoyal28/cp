#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    string str;
    cin >> str;
    string res = "";
    int st = 0;
    while (st < n && str[st] == '0')
    {
        res += '0';
        st++;
    }
    int end = n - 1;
    string secondRes = "";
    while (end >= st && str[end] == '1')
    {
        secondRes += '1';
        end--;
    }
    if (end > st)
    {
        secondRes += '0';
    }
    reverse(secondRes.begin(), secondRes.end());
    string result = res + secondRes;
    cout << result << "\n";
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
