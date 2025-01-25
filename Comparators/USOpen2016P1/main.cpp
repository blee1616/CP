#include <bits-stdc++.h> //change the "-" to a "/"
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

bool cmp(int a, int b) {
	if (x[a] == x[b]) return y[a] < y[b];
	return x[a] < x[b];
}

bool cmp1(int a, int b) {
	if (y[a] == y[b]) return x[a] < x[b];
	return y[a] < y[b];
}

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() { 
    setIO("reduce");
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        
    }
}