#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int

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
    sort(arr.begin(), arr.end());
    int st = 0;
    int end = n - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == mid + 1)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << st + 1 << "\n";
    return 0;
}