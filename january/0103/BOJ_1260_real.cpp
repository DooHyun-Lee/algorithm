#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int N, M, V;
vector<int> a[1001];	// 하나의 정점과 연결된 다른 정점들 저장
int cd[1001];	// dfs visited
int cb[1001];  // bfs visited

void dfs(int x) {
	if (cd[x]) return;
	cd[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	cb[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!cb[y]) {
				q.push(y);
				cb[y] = true;
			}
		}
	}
}

int main() {

	cin >> N >> M >> V;

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		a[v1].push_back(v2);
		a[v2].push_back(v1);
	}

	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(V);
	cout << '\n';
	bfs(V);
}
