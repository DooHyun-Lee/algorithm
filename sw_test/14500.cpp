#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
int paper[501][501];
int visited[501][501];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int ret;
void solve(int y, int x, int sum, int cnt)
{
	if (cnt == 4)
	{
		ret = max(ret, sum);
		return;
	}

	for (int next = 0; next < 4; ++next) {
		int ny = y + dy[next];
		int nx = x + dx[next];
		if (!visited[ny][nx] && ny >= 0 && ny < N && nx >= 0 && nx < M) {
			visited[ny][nx] = true;
			solve(ny, nx, sum + paper[ny][nx], cnt + 1);
			visited[ny][nx] = false;
		}
	}

}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> paper[i][j];
		}

	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			ret = 0;
			// 한번에 갈수있는 테트로미노 처리
			visited[i][j] = true;
			solve(i, j, paper[i][j], 1);

			// 마지막모양 테트로미노 예외처리
			if (j + 2 < M) {
				int temp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2];
				//  ㅁ
				//ㅁㅁㅁ
				if (i - 1 >= 0) {
					int temp2 = temp + paper[i - 1][j + 1];
					ret = max(ret, temp2);
				}
				//ㅁㅁㅁ
				//  ㅁ
				if (i + 1 < N) {
					int temp2 = temp + paper[i + 1][j + 1];
					ret = max(ret, temp2);
				}
			}
			if (i + 2 < N) {
				int temp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j];
				//ㅁ
				//ㅁㅁ
				//ㅁ
				if (j + 1 < M) {
					int temp2 = temp + paper[i + 1][j + 1];
					ret = max(ret, temp2);
				}
				//  ㅁ
				//ㅁㅁ
				//  ㅁ
				if (j - 1 >= 0) {
					int temp2 = temp + paper[i + 1][j - 1];
					ret = max(ret, temp2);
				}
			}

			visited[i][j] = false;
			ans = max(ans, ret);
		}
	cout << ans << "\n";
	return 0;
}
