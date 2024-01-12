#include <iostream>
#define ll long long int
using namespace std;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0)
    {
        cout << "1" << endl;
        return;
    }
    cout << a + min(b, c) * 2 + min(a + 1, abs(c - b) + d) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tests;
    cin >> tests;
    while (tests--)
    {
        solve();
        puts("");
    }
}