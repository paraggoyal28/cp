#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int

vector<ll> findOriginalArray(vector<ll> &diffArray, ll n)
{
    int maxN = 1e9;
    sort(diffArray.begin(), diffArray.end());
    vector<ll> originalArray;
    ll m = diffArray.size();
    for (int i = 0; i < m; i += --n)
    {
        originalArray.push_back(diffArray[i]);
    }
    originalArray.push_back(maxN);
    return originalArray;
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
        ll n;
        cin >> n;
        ll m = (n * (n - 1)) / 2;
        vector<ll> b(m);
        for (ll i = 0; i < m; ++i)
        {
            cin >> b[i];
        }

        vector<ll> ans = findOriginalArray(b, n);
        for (ll num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}