// Question Link: https://codeforces.com/contest/120/problem/F

#include <bits/stdc++.h>
using namespace std;
 
// First, find the furthes node to any leaf node
int bfs(int leafNode, vector<vector<int>> &graph) {
	int longestPathLen = 0, furthesNode;
	queue<vector<int>> todo;
	todo.push({leafNode, 0});
	vector<bool> seen(graph.size(), false);
	seen[leafNode] = true;
	while (!todo.empty()) {
		vector<int> cur = todo.front();
		todo.pop();
		// Update furthesNode
		if (cur[1] > longestPathLen) {
			longestPathLen = cur[1];
			furthesNode = cur[0];
		}
		for (int &neigh : graph[cur[0]]) {
			if (seen[neigh] == false) {
				seen[neigh] = true;
				todo.push({neigh, cur[1] + 1});
			}
		}
	}
	return furthesNode;
}

// Second, find longest path starting from the node found in bfs
int dfs(int cur, vector<vector<int>> &graph, vector<bool> &seen) {
	seen[cur] = true;
	int depth = 0;
	for (int &neigh : graph[cur]) {
		if (seen[neigh] == false) {
			 depth = max(depth, dfs(neigh, graph, seen) + 1);
		}
	}
	return depth;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int T, N, p1, p2, furthesNode, longestPathLen = 0;
	cin >> T;
	// For each spider/grahp
	while (T--) {
		// Number of pairs, build undirected graph
		cin >> N;
		vector<vector<int>> graph(N + 1);
        vector<bool> seen(N + 1, false);
		int leafNode;
		while (--N) {
			cin >> p1 >> p2;
			graph[p1].push_back(p2);
			graph[p2].push_back(p1);
		}
		furthesNode = bfs(p1, graph); // Start from any node
		longestPathLen += dfs(furthesNode, graph, seen); // Find longest path for current spider
	}
	cout << longestPathLen;
	return 0;
}