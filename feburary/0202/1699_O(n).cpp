#include <stdio.h>
#include<iostream>
int d[100000];
using namespace std;
int main()
{
	int N, ans = 0;
	scanf("%d", &N);
	for (int n = 1; n*n <= N; n++) {
		d[n*n] = 1;
		for (int m = 1; m <= n; m++)
			if (n*n + m*m <= N && d[n*n + m*m]==0)
				d[n*n + m*m] = 2;
	}   // 1, 2에 대한 케이스 미리 계산 (sqrt(n)*sqrt(n) 이므로 총 O(n))
	
	for (int n = 0; n <= N; n++)
	{
		if (d[n] == 0 || d[N-n]==0) continue;   // 둘다 0인 케이스 제외
		if (d[N]==0 || d[N] > d[n] + d[N - n])  // 처음 더하는 케이스 || 새로운 더 작은 합 출연 -> n과 N-n 이라는 부분 문제로 분할
			d[N] = d[n] + d[N - n]; // update
	}

	printf("%d", d[N]);
}
