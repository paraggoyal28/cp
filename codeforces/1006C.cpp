#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    ll sumA = 0;
    ll sumC = 0;
    ll i = 0;
    ll j = n - 1;
    ll ans = 0;
    while (i <= j)
    {
        if (sumA <= sumC)
        {
            if (sumA == sumC)
            {
                ans = sumA;
            }
            sumA += arr[i];
            i++;
        }
        else
        {
            sumC += arr[j];
            j--;
        }
    }
    if (sumA == sumC)
    {
        ans = sumA;
    }
    cout << ans << endl;
    return 0;
}