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

int n;
vector<vector<int>> adj;  // adjacency list
vector<bool> visited;     // stores which nodes have been visited

double ans;

void dfs(int node, int current_length, double current_probability) {
	visited[node] = true;
	int possible_moves = 0;
	// count the number of cities we can move to
	for (int x : adj[node]) {
		if (!visited[x]) { possible_moves++; }
	}

	if (!possible_moves) {
		// if there are no cities to move to, the path has ended
		ans += current_length * current_probability;
	} else {
		// update the new probability by dividing it
		// by the number of possible cities
		double new_probability = current_probability / possible_moves;
		for (int x : adj[node]) {
			if (!visited[x]) { dfs(x, current_length + 1, new_probability); }
		}
	}
}

int main() {
	cin >> n;
	adj.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// the traversal starts with node 1, path length 0, and probability 100%.
	dfs(1, 0, 1);

	cout << setprecision(10) << ans << endl;
}