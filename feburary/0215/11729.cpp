#include<cstdio>

char ans[1 << 22];
int i=0;
void move(int from, int to, int n) {
	if (n == 0)return;
	int via = 6 - from - to;
	move(from, via, n - 1);
	ans[i++] = from + '0';
	ans[i++] = ' ';
	ans[i++] = to + '0';
	ans[i++] = '\n';
	move(via, to, n - 1);
}

int main() {
	int n; scanf("%d",&n);
    printf("%d\n",(1<<n) - 1);
	move(1, 3, n);
	puts(ans);
}

