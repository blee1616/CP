#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <limits>
using namespace std;

using ll = long long;

using vi = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<ll,ll>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() { 
    setIO("");
    ll u,p,b,m,price,count = 0,tot = 0;
    string y;
    vi v1,v2;
    cin >> u >> p >> b >> m;
    for (int i = 0; i < m; i++) {
        cin >> price >> y;
        if(y == "USB") v1.pb(price);
        else v2.pb(price);
    }
    sort(all(v1)),sort(all(v2));
    while (u-- && !v1.empty()) {
        count++;
        tot += v1.front();
        v1.erase(v1.begin());
    }
    while (p-- && !v2.empty()) {
        count++;
        tot += v2.front();
        v2.erase(v2.begin());
    }
    while (b-- && (!v1.empty() || !v2.empty())) {
        count++;
        if (v1.empty()) {
            tot+=v2.front();
            v2.erase(v2.begin());
        } 
        else if (v2.empty()) {
            tot+=v1.front();
            v1.erase(v1.begin());
        } 
        else {
            if (v1.front() < v2.front()) {
                tot+=v1.front();
                v1.erase(v1.begin());
            }
            else {
                tot+=v2.front();
                v2.erase(v2.begin());
            }
        }
    }
    cout << count << " " << tot;
}
