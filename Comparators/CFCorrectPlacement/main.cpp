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
const ll maxN = 1000000;
vector <pair <pi,ll>> sorted(maxN);
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
bool sortbygreatest(const pair<int,int> &a,
              const pair<int,int> &b)
{
    ll g1,g2;
    if (a.f > a.s) g1 = a.f;
    else g1 = a.s;
    if (b.f > b.s) g2 = b.f;
    else g2 = b.s;
    return g1 < g2;
}
int findInd(pi checkpair, ll N) {
    for (int i = 0; i < N; i++) {
        if (sorted[i].f == checkpair) {
            return i;
        }
    }
    return 0;
}
int main() { 
    setIO("");
    ll N, Q;
    cin >> Q;
    for (int j = 0; j < Q; j++) {
        cin >> N;
        ll a,b;
        vector <pi> v(N);
        vector <pi> v1(N);
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            v[i] = mp(a,b);
            v1[i] = mp(a,b);
            sorted[i] = mp(mp(a,b),i);
        }
        sort(all(v));
        pi x = v[0];
        int ind1 = findInd(x,N);
        sort(all(v),sortbysec);
        pi y = v[0];
        int ind2 = findInd(y,N);
        sort(all(v),sortbygreatest);
        pi z = v[0];
        int ind3 = findInd(z,N);
        for (int i = 0; i < N; i++) {
            if (v1[i].f>x.f && v1[i].s>x.s || v1[i].f>x.s && v1[i].s>x.f) cout << ind1 + 1 << " ";
            else if(v1[i].f>y.f && v1[i].s>y.s || v1[i].f>y.s && v1[i].s>y.f) cout << ind2 + 1 << " ";
            else if (v1[i].f>z.f && v1[i].s>z.s || v1[i].f>z.s && v1[i].s>z.f) cout << ind3 + 1 << " ";
            else cout << -1 << " ";
        }
        cout << endl;
    }
}