#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int

ll findPowerOfTwo(ll num)
{
    ll count = 0;
    while (num % 2 == 0)
    {
        num /= 2;
        count += 1;
    }
    return count;
}

ll solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll count = 0;
    vector<ll> operationCount;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
        count += findPowerOfTwo(a[i]);
        operationCount.push_back(findPowerOfTwo(i + 1));
    }

    sort(operationCount.begin(), operationCount.end(), greater<ll>());
    ll remCount = n - count;
    ll operations = 0;
    ll k = 0;
    while (remCount > 0 && k < n)
    {
        remCount -= operationCount[k];
        k++;
        operations += 1;
    }
    return remCount > 0 ? -1 : operations;
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