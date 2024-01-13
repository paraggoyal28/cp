#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define ll long double
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll groups = 1;
    vector<ll> diff;
    for (ll i = 1; i < n; ++i)
    {
        if (arr[i] - arr[i - 1] > x)
        {
            groups += 1;
            diff.push_back(arr[i] - arr[i - 1]);
        }
    }
    sort(diff.begin(), diff.end());

    ll diffSize = diff.size();
    for (ll i = 0; i < diffSize; ++i)
    {
        ll difference = ceil((diff[i] * 1.0) / x) - 1;
        if (k >= difference)
            k -= difference;
        else
            break;
        groups -= 1;
    }

    cout << groups << endl;
}

// 1 9 3 8/3 = 3 - 1 = 2  1 4 7 9