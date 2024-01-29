#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL Ceil(LL x, LL y) {
    return x / y + (x % y != 0);
}

LL J(LL n, LL q) {
    LL D = 1, end = (q - 1) * n;
    while (D <= end) {
        D = Ceil(q * D, q - 1);
    }
    return q * n + 1 - D;
}

int main() {
    LL n, q;
    while (~scanf("%lld%lld", &n, &q)) {
        printf("%lld\n", J(n, q));
    }
    return 0;
}
