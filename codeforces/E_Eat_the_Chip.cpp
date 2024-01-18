#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string solve()
{
    ll h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa >= xb)
        return "Draw";
    ll par = (xb - xa) % 2;
    ll s = (xb - xa + 1) / 2;
    if (par == 1)
    {
        // either winner is alice or draw
        // going right
        if (min(w, ya + s) < min(w, yb + s - 1))
            return "Draw";
        // going left
        else if (max(1LL, ya - s) > max(1LL, yb - s + 1))
            return "Draw";
        return "Alice";
    }
    else
    {
        // either winner is bob or draw
        // going right
        if (min(w, ya + s) > min(w, yb + s))
            return "Draw";
        else if (max(1LL, ya - s) < max(1LL, yb - s))
            return "Draw";
        return "Bob";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cout << solve() << "\n";
    }
    return 0;
}