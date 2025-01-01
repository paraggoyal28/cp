#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void findSubordinates(ll start, vector<ll> &noOfSubordinates, vector<ll> suboordinates[])
{
    for (ll suboordinate : suboordinates[start])
    {
        findSubordinates(suboordinate, noOfSubordinates, suboordinates);
        noOfSubordinates[start] += noOfSubordinates[suboordinate] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll directboss;
    vector<ll> suboordinates[n + 1];
    for (ll i = 1; i < n; ++i)
    {
        cin >> directboss;
        suboordinates[directboss].push_back(i + 1);
    }
    vector<ll> noOfSubordinates(n + 1, 0LL);
    findSubordinates(1LL, noOfSubordinates, suboordinates);
    for (ll i = 1; i <= n; ++i)
    {
        cout << noOfSubordinates[i] << "\n";
    }
    return 0;
}
