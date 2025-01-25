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

const ll maxn = 5000;
bool visited[maxn];
ll curr = 0;
bool check = false;
ll ans = 1;
ll ind = 0;
vector <vector<pi>> v(maxn);
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
void dfs(ll node,ll k){
    visited[node] = true;
    for(pi next : v[node]){
        if(!visited[next.f]){
            curr++;
            if (check) ans++;
            if (!check) {
                if (next.s < k) {
                    check = true;
                    ind = curr;
                    ans++;
                }
            } 
            dfs(next.f,k);
        }
    }
    curr--;
    if (curr < ind) {
        check = false;
        ind = 0;
    }
}
int main() { 
    setIO("mootube"); 
    ll n,q,x,y,z;;
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) { 
        cin >> x >> y >> z;
        x--,y--;
        v[x].pb(mp(y,z));
        v[y].pb(mp(x,z));
    }
    ll k, start;
    for (int i = 0; i < q; i++) {
        cin >> k >> start;
        start--;
        dfs(start,k);
        cout << n - ans << endl;
        ans = 1;
        check = false;
        ind = 0;
        for (int j = 0; j < n; j++) {
            visited[j] = false;
        }
    }
}