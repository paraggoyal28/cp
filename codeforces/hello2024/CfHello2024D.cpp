/*
author: parag kumar goyal
problem: d 01 Tree
contest: Hello 2024
platform: codeforces
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
int a[MAXN];
int prv[MAXN], nxt[MAXN];
bool in[MAXN];

bool good(int i) {
	if(i < 1 || i > n) {
		return 0;
	}
	
	return a[prv[i]] == a[i]-1 || a[nxt[i]] == a[i] - 1; 
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		priority_queue<pair<int, int>> pq;
		for(int i = 1; i <= n; ++i) {
			prv[i] = i - 1;
			nxt[i] = i + 1;
			in[i] = 0;
			cin >> a[i];
		}
		
		a[n+1] = a[0] = -2;
		
		for(int i = 1; i <= n; ++i) {
			if(good(i)) {
				in[i] = 1;
				pq.push({a[i], i});
			}
		}
		
		while(!pq.empty()) {
			auto [_, i] = pq.top();
			pq.pop();
			nxt[prv[i]] = nxt[i];
			prv[nxt[i]] = prv[i];
			if(!in[prv[i]] && good(prv[i])) {
				in[prv[i]] = 1;
				pq.push({a[prv[i]], prv[i]});
			}
			if(!in[nxt[i]] && good(nxt[i])) {
				in[nxt[i]] = 1;
				pq.push({a[nxt[i]], nxt[i]});
			}
		}
		
		int mn = n, bad = 0;
		for(int i = 1; i <= n; ++i) {
			bad += !in[i];
			mn = min(mn, a[i]);
		}
		
		if(bad == 1 && mn == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
}
