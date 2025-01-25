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

const int maxn = 1000;
int n, target;
int milk1;
int milk2;
int mindiff = 1e5;
bool visited[maxn][maxn][maxn];  // keeps track of which nodes have been visited
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
void floodfill(int curr1, int curr2, int num) {
	if (visited[curr1][curr2][num] || num > n) return;
    mindiff = min(mindiff,abs(curr1+curr2-target));
    visited[curr1][curr2][num] = true;
	// recursively call flood fill for neighboring squares
	floodfill(curr1, 0, num+1);
	floodfill(0, curr2, num+1);
	floodfill(curr1, milk2, num+1);
	floodfill(milk1, curr2, num+1);
    int diff1 = milk1 - curr1;
    if (curr2 >= diff1) {
        floodfill(milk1,curr2-diff1,num+1);
    }
    else {
        floodfill(curr1+curr2,0,num+1);
    }
    int diff2 = milk2 - curr2;
    if (curr1 >= diff2) {
        floodfill(curr1-diff2,milk2,num+1);
    }
    else {
        floodfill(0,curr1+curr2,num+1);
    }
}

int main() {
    setIO("pails");
    cin >> milk1 >> milk2 >> n >> target;
	/*
	 * input code and other problem-specific stuff here
	 */

    floodfill(0,0,0);
    cout << mindiff;
}