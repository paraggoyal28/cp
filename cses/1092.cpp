#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll sumOfFirstN = (n * (n + 1)) / 2;
    if (sumOfFirstN % 2)
    {
        cout << "NO\n";
    }
    else
    {
        ll targetSum = sumOfFirstN / 2;
        vector<ll> firstGroup, secondGroup;
        int maxNum = n;
        while (targetSum >= maxNum)
        {
            targetSum -= maxNum;
            firstGroup.push_back(maxNum);
            maxNum -= 1;
        }

        if (targetSum > 0)
        {
            firstGroup.push_back(targetSum);
        }

        for (ll i = maxNum; i >= 1; --i)
        {
            if (i != targetSum)
            {
                secondGroup.push_back(i);
            }
        }

        cout << "YES\n";
        cout << firstGroup.size() << "\n";
        for (ll num : firstGroup)
        {
            cout << num << " ";
        }
        cout << "\n";
        cout << secondGroup.size() << "\n";
        for (ll num : secondGroup)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
}