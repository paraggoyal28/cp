#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isSuitable(int preferredSize, int actualSize, int maxAllowedDif)
{
    return (actualSize >= preferredSize - maxAllowedDif) && (actualSize <= preferredSize + maxAllowedDif);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> candidatePref(n);
    vector<ll> apartmentSize(m);
    for (ll &cp : candidatePref)
    {
        cin >> cp;
    }

    for (ll &sz : apartmentSize)
    {
        cin >> sz;
    }

    sort(candidatePref.begin(), candidatePref.end());
    sort(apartmentSize.begin(), apartmentSize.end());

    int candidateIdx = 0, apartmentIdx = 0;
    int apartmentsFilled = 0;
    while (candidateIdx < n && apartmentIdx < m)
    {
        if (isSuitable(candidatePref[candidateIdx], apartmentSize[apartmentIdx], k))
        {
            apartmentsFilled++;
            candidateIdx++;
            apartmentIdx++;
        }
        else if (candidatePref[candidateIdx] - k > apartmentSize[apartmentIdx])
        {
            apartmentIdx++;
        }
        else
        {
            candidateIdx++;
        }
    }

    cout << apartmentsFilled << "\n";
    return 0;
}