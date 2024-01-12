/*
author: parag kumar goyal
contest: Codeforces Round 918(Div. 4)
problem: C. Can I Square ? 
*/
#include <iostream>
#include <math.h>
using namespace std;
#define ll long long int

bool isSquare(long double num) {
	long long root = floor(sqrt(num));
	return root * root == num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll tests;
	cin >> tests;
	while(tests--) {
		ll n;
		cin >> n;
		ll size;
		long double sumOfSizes = 0;
		for(ll i = 0; i < n; ++i)  {
			cin >> size;
			sumOfSizes += (long double) size;
		}
		if(isSquare(sumOfSizes)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
