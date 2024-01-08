#include <bits/stdc++.h>
using namespace std;

int extendedEuclideanAlgorithm(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = extendedEuclideanAlgorithm(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, x, y;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        int d = extendedEuclideanAlgorithm(a, b, x, y);
        printf("%d %d %d\n", x, y, d);
    }
}