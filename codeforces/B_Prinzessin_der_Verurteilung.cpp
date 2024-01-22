#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll findNum(const string &str)
{
    ll res = 0;
    ll n = str.length();
    ll base = 1;
    for (ll i = n - 1; i >= 0; --i)
    {
        ll charVal = (str[i] - 'a') + 1;
        res += charVal * base;
        base *= 26;
    }
    return res;
}

string convertToStr(ll num)
{
    string ans = "";
    while (num > 0)
    {
        num--;
        ll rem = num % 26;
        ans += rem + 'a';
        num /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string getNext(const string &str)
{
    ll num = findNum(str);
    num += 1;
    return convertToStr(num);
}

bool cmp(string &a, string &b)
{
    if (a.length() > b.length())
    {
        return false;
    }
    else if (a.length() < b.length())
    {
        return true;
    }
    else
    {
        return a < b;
    }
}

void solve()
{
    ll n;
    cin >> n;
    string str;
    cin >> str;
    unordered_set<string> substrs;

    for (ll i = 0; i < n; ++i)
    {
        string s = "";
        for (ll j = i; j < i + 6 && j < n; ++j)
        {
            s += str[j];
            substrs.insert(s);
        }
    }

    vector<string> substrsVec(substrs.begin(), substrs.end());
    sort(substrsVec.begin(), substrsVec.end(), cmp);
    ll m = substrsVec.size();
    string start = "a";
    if (substrsVec[0] != start)
    {
        cout << start << endl;
        return;
    }
    for (ll i = 0; i < m - 1; ++i)
    {
        string next = getNext(substrsVec[i]);
        if (next != substrsVec[i + 1])
        {
            cout << next << endl;
            return;
        }
    }

    cout << getNext(substrsVec[m - 1]) << endl;
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
