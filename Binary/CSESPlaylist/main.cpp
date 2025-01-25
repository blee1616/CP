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
#include <climits>
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
    int n;
    set<int> heard;
    int i = 0, j = 0, ans = 0;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (i < n && j < n) {
        while (j < n && !heard.count(v[j])) {
            heard.insert(v[j]);
            ans = max(ans,j-i+1);
            j++;
        }
        if (j < n) {
            heard.erase(v[i]);
            i++;
        }
    }
    cout << ans;
}