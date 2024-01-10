#include <iostream>
using namespace std;
#define ll long long int

bool isPossible(ll teams, ll coders, ll mathematicians, ll others)
{
    return coders >= teams && mathematicians >= teams && coders + mathematicians + others >= teams * 3;
}

void solve()
{
    ll coders, mathematicians, others;
    cin >> coders >> mathematicians >> others;
    ll minTeams = 0;
    ll maxTeams = min(coders, mathematicians);
    ll maxPossibleTeams = 0;
    while (minTeams <= maxTeams)
    {
        ll midTeams = minTeams + (maxTeams - minTeams) / 2;
        if (isPossible(midTeams, coders, mathematicians, others))
        {
            maxPossibleTeams = midTeams;
            minTeams = midTeams + 1;
        }
        else
        {
            maxTeams = midTeams - 1;
        }
    }
    cout << maxPossibleTeams << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}