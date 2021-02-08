#include <cstdio>
#include <queue>
using namespace std;

int n;
int map[100][100];
int dist[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j, int num) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	map[i][j] = num;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		dist[x][y] = 1;
		q.pop();
		for (int k=0; k<4; ++k) {
			int nx = x+dx[k];
			int ny = y+dy[k];
			if (0<=nx && nx<n && 0<=ny && ny<n && dist[nx][ny]==1 && map[nx][ny]==0) {
				q.push(make_pair(nx, ny));
				map[nx][ny] = num;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			scanf("%d", dist[i]+j);
		}
	}
	
	int group = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (dist[i][j]==1 && map[i][j]==0) {
				bfs(i, j, ++group);
			}
		}
	}
	
	int ans = 0;
	for (int d=1; d<=n; ++d) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (map[i][j]!=0 && dist[i][j]==d) {
					for (int k=0; k<4; ++k) {
						int ni = i+dx[k];
						int nj = j+dy[k];
						if (0<=ni && ni<n && 0<=nj && nj<n) {
							if (map[ni][nj]==0 && dist[ni][nj]==0) {
								map[ni][nj] = map[i][j];
								dist[ni][nj] = d+1;
							} else if (map[ni][nj]!=0 && map[ni][nj]!=map[i][j]) {
								if (ans==0 || ans>dist[i][j]+dist[ni][nj]-2) {
									ans = dist[i][j]+dist[ni][nj]-2;
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
