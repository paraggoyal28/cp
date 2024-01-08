/*
Miller-Rabin primality test suggests that it is used to test whether the given number
N is prime or not (with some error).
Miller-Rabin primality test is based on Fermat's little theorem which says,
for prime P , a^(p-1) == 1 (mod p).
n will be odd
n-1 = 2^s.d d is odd

*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool isPrime(u64 n)
{ // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

int main()
{
    lli t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (isPrime(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}