// fast way to compute gcd

#include <cstdio>
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll a, b;
int main() {
    scanf("%lld %lld", &a, &b);
    int r = gcd(a, b);
    while (r--) printf("1");
    return 0;
}
