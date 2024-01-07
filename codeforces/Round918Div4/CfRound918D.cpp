/*
author: parag kumar goyal
problem: Problem D Unnatural Language Processing
contest: CodeForces Round 918(Div. 4) 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isVowel(char ch) {
	return (ch == 'a' || ch == 'e');
}

string solve() {
    ll n;
    cin >> n;
    string str;
    cin >> str;
    string new_str = "";
    for(ll i = 0; i < n-2; ++i) {
        new_str += str[i];
        if(isVowel(str[i])){
			if(isVowel(str[i+2])) {
				new_str += '.';
			} else {
				i += 1;
				new_str += str[i];
				new_str += '.';
			}
        }
    }
	for(int i = n-2; i < n; ++i) 
		new_str += str[i];
    return new_str;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tests;
    cin >> tests;
    while(tests--) {
        cout << solve() << "\n";
    }
    return 0;

}
