#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll totalChildren, maxAllowedWeight;
    cin >> totalChildren >> maxAllowedWeight;

    vector<ll> weights(totalChildren);

    for (ll &w : weights)
    {
        cin >> w;
    }

    sort(weights.begin(), weights.end());

    int lightIdx = 0, heavyIdx = totalChildren - 1;
    int noOfGondola = 0;
    while (lightIdx <= heavyIdx)
    {
        if (lightIdx < heavyIdx && weights[heavyIdx] + weights[lightIdx] <= maxAllowedWeight)
        {
            lightIdx++;
        }
        heavyIdx--;
        noOfGondola++;
    }

    cout << noOfGondola << "\n";
    return 0;
}