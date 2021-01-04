#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int N, M, V;
vector<int> a[1001];	// 크기가 1001인 int 형 벡터의 배열 생성
int d_flag[1001];	// dfs visited
int b_flag[1001];  // bfs visited

void dfs(int x) {
	if (d_flag[x]) return;
	d_flag[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	b_flag[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!b_flag[y]) {
				q.push(y);
				b_flag[y] = true;
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
