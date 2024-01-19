#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1025;

int n;
int in[N];
bool is[N];

bool check(ll k)
{
    for (ll i = 1; i <= n; ++i)
    {
        if (!is[in[i] ^ k])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    for (ll i = 0; i < N; ++i)
    {
        is[i] = false;
    }
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> in[i];
        is[in[i]] = true;
    }

    for (ll k = 1; k < 1024; ++k)
    {
        if (check(k))
        {
            cout << k << endl;
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        solve();
    }
    return 0;
}