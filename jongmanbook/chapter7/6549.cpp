#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>
using namespace std;

int n;
long long histo[100000];

long long solve(int left, int right) {
	if (left == right) return histo[left];
	int mid = (left + right) / 2;
	long long ret = max(solve(left, mid), solve(mid + 1, right));
	int lo = mid, hi = mid + 1;
	long long height = min(histo[lo], histo[hi]);
	ret = max(ret, height * 2);

	while (lo > left || hi < right) {       // 이 부분이 or 조건임에 유의
		if (hi < right && (lo == left || histo[hi + 1] > histo[lo - 1])) {
			hi++;
			height = min(histo[hi], height);
		}
		else {
			lo--;
			height = min(histo[lo], height);
		}
		ret = max(ret, (hi-lo+1)*height);
	}
	return ret;
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			scanf("%lld", &histo[i]);

		long long ans = solve(0, n - 1);
		printf("%lld\n", ans);

		memset(histo, 0, sizeof(histo));
	}
	return 0;
}
