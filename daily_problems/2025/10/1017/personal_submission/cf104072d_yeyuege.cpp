#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	set<ll>st;
	ll n;
	cin >> n;
	st.insert(0);
	for (ll i = 0; i <= 9; i++) {
		for (ll j = 0; j <= 9; j++) {
			set<ll> temp;
			temp.insert(0);
			int f = 1;
			while (f) {
				f = 0;
				set<ll> q;
				for (ll x : temp) {
					if (!temp.count(x * 10 + i) && x * 10 + i <= n) {
						f = 1;
						q.insert(x * 10 + i);
					}

					if (!temp.count(x * 10 + j) && x * 10 + j <= n) {
						f = 1;
						q.insert(x * 10 + j);
					}
				}
				for (ll x : q) {
					temp.insert(x);
				}
			}

			for (ll x : temp) {
				st.insert(x);
			}
		}
	}

	int ans = 0;
	for (ll x : st) {
		if (st.count(n - x)) ans++;
	}
	if (st.count(n / 2LL)) ans++;
	cout << ans / 2 << endl;
	return 0;
}
