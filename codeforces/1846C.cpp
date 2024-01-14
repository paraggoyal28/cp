#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int

bool cmp(pair<pair<ll, ll>, ll> &scoreA, pair<pair<ll, ll>, ll> &scoreB)
{
    if (scoreA.first.first == scoreB.first.first && scoreA.first.second == scoreB.first.second)
    {
        return scoreA.second < scoreB.second;
    }
    else if (scoreA.first.first == scoreB.first.first)
    {
        return scoreA.first.second < scoreB.first.second;
    }
    return scoreA.first.first > scoreB.first.first;
}

ll solve()
{
    ll n, m, h;
    cin >> n >> m >> h;
    vector<vector<ll>> problemsSolved(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            cin >> problemsSolved[i][j];
        }
        sort(problemsSolved[i].begin(), problemsSolved[i].end());
        for (ll j = 1; j < m; ++j)
        {
            problemsSolved[i][j] += problemsSolved[i][j - 1];
        }
    }

    vector<pair<pair<ll, ll>, ll>> scores;
    for (ll i = 0; i < n; ++i)
    {
        ll penalty = 0, score = 0;
        for (ll j = 0; j < m; ++j)
        {
            if (problemsSolved[i][j] <= h)
            {
                score += 1;
                penalty += problemsSolved[i][j];
            }
            else
            {
                break;
            }
        }
        scores.push_back({{score, penalty}, i});
    }
    sort(scores.begin(), scores.end(), cmp);
    for (ll i = 0; i < n; ++i)
    {
        if (scores[i].second == 0)
        {
            return i + 1;
        }
    }
    return -1;
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
        cout << solve() << endl;
    }
    return 0;
}