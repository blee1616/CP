#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
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

int main() {
	int n, q, x, count = 1;
	cin >> n >> q;
    map <ll,ll> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[--x] = i;
    }
    for (int i = 0; i < n-1; i++) {
        if (m[i] > m[i+1]) count++;
    }
    while(--q) {
        cin >> a >> b;
        int olda = m[a], oldb = m[b];
        if (m[a] > m[b]) cond2 = true;
        a--,b--;
        ll temp = m[a];
        m[a] = m[b];
        m[b] = temp;
        if (a+1 == b) {
            if (olda > oldb) count++;
        }
        else if(a-1==b) {
            if (olda < oldb) count--;
        }
        if (olda > m[a-1] && m[a] < m[a-1])
    }
}