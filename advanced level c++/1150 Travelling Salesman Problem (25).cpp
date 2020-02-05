#include <iostream>
#include <vector>
#include <set>
using namespace std;
int e[210][210], n, m, k, ans = 0x3fffffff, ansid;
vector<int> v;
void check(int index) {
	int sum = 0, cnt, flag = 1;
	scanf("%d", &cnt);
	set<int> s;
	vector<int> v(cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &v[i]);
		s.insert(v[i]);
	}
	for (int i = 0; i < cnt - 1; i++) {
		if (e[v[i]][v[i+1]] == 0) flag = 0;
		sum += e[v[i]][v[i+1]];
	}
	if (flag == 0)
		printf("Path %d: NA (Not a TS cycle)\n", index);
	else if (v[0] != v[cnt-1] || s.size() != n)
		printf("Path %d: %d (Not a TS cycle)\n", index, sum);
	else {
		if (cnt != n + 1) printf("Path %d: %d (TS cycle)\n", index, sum);
		else printf("Path %d: %d (TS simple cycle)\n", index, sum);
		if (sum < ans) {
			ans = sum;
			ansid = index;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int c1, c2, dis;
		scanf("%d%d%d", &c1, &c2, &dis);
		e[c1][c2] = e[c2][c1] = dis;
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) check(i);
	printf("Shortest Dist(%d) = %d\n", ansid, ans);
	return 0;
}