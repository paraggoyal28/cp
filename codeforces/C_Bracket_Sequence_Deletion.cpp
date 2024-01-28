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

bool isBalanced(string str)
{
}

bool isPalindrome(string str)
{
    string rev(str);
    reverse(rev.begin(), rev.end());
    return str == rev;
}
char getOpposite(char ch)
{
    return ch == '(' ? ')' : '(';
}

void solve()
{
    /*
    find least size prefix
    least 2
    balanced
    ()(()),()(),(()(()))
    palindrome
    ((((, ((), ()(
    )((()(
    */
    int n;
    cin >> n;
    string sequence;
    cin >> sequence;
    // while seq[l..r] is not balanced or palindrome
    // increase r
    // if r < n, l = r + 1, r = r + 1
    // left characters = n - l
    // operations when
    // stack, if top of stack is reverse of current
    // and stack is empty
    // checking palindrome
    // i
    int operations = 0;
    if (n == 1)
    {
        cout << "0 1\n";
        return;
    }
    int l = 0;
    int r = 1;
    while (r < n)
    {
        while (r < n && sequence[l] == ')' && sequence[r] == '(')
        {
            r++;
        }
        if (r < n)
        {
            l = r + 1;
            r = r + 2;
            operations += 1;
        }
    }
    cout << operations << " " << n - l << "\n";
}
signed main()
{
    FastIO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
