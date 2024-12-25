#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll noOfCustomers;
    cin >> noOfCustomers;
    vector<ll> arrivalTime(noOfCustomers);
    vector<ll> departureTime(noOfCustomers);
    for (ll custIdx = 0; custIdx < noOfCustomers; ++custIdx)
    {
        cin >> arrivalTime[custIdx] >> departureTime[custIdx];
    }
    sort(arrivalTime.begin(), arrivalTime.end());
    sort(departureTime.begin(), departureTime.end());
    ll maxCustomersAtATime = 1;
    ll customersAtATime = 0;
    ll arrivalIdx = 0, departureIdx = 0;
    while (arrivalIdx < noOfCustomers && departureIdx < noOfCustomers)
    {
        if (arrivalTime[arrivalIdx] < departureTime[departureIdx])
        {
            customersAtATime++;
            arrivalIdx++;
        }
        else
        {
            customersAtATime--;
            departureIdx++;
        }
        maxCustomersAtATime = max(maxCustomersAtATime, customersAtATime);
    }
    cout << maxCustomersAtATime << "\n";
    return 0;
}