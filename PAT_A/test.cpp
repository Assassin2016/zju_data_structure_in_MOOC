/**
 * Template of Dijkstra + DFS:
 * ----------------------------------------------------------------
 * 1. Calculate the shotest path(s) using Dijkstra algorithm first, 
 * 2. Select the optimal path using other measurement
 */
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3fffffff;
#define MAXV 1000
int d[MAXV];
bool visit[MAXV];
vector<int> pre[MAXV];

void Dijkstra(int s)
{
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++)
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++)
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (d[u] + G[u][v] == d[v])
					pre[v].push_back(u);
			}
	}
}

/**           V7
 *          /  \
 *        V5   V6
 *         |   / \
 *        V1  V3  V4
 *             |  |
 *            V2  V2
 *             |  |
 *            V1  V1
 */
int start, end;				// starting/ending vertex
int optValue;				// second measurement
vector<int> path, tmpPath;	// elements in tmpPath is in reversed order
void DFS(int v)
{
	if (v == start) {
		tmpPath.push_back(v);
		int value;
		if (value better than optValue) {
			optValue = value;
			path = tmpPath;
		}
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i]);
	tmpPath.pop_back();
}

