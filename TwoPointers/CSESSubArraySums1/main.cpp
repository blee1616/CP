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
using namespace std;

using ll = long long;

using vi = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
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
    ll N, target, ans = 0, right = 0, left = 0, curr = 0;
    cin >> N >> target;
    vi v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    while (left < N && right < N) {
        while (right < N) {
            curr += v[right++];
            if (curr == target) {
                ans++;
                break;
            }
            else if (curr > target) {
                curr -= v[--right];
                break;
            }
        }
        curr -= v[left++];
    }
    cout << ans;
}