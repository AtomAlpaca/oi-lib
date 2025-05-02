// https://atcoder.jp/contests/arc154/tasks/arc154_e

#include "../math/all.hpp"
#include <cstddef>
#include <cstdio>

typedef long long i64;
const i64 MOD = 998244353;
const size_t MAX = 2e5 + 5;

i64 n, m, ans, p[MAX];

OI_math::Base <200005, 998244353> b;

int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) { scanf("%lld", &p[i]); }

    for (int i = 1; i <= n; ++i)
    {
        i64 P = b.qpow((b.comb(n - i + 1, 2) + b.comb(i, 2)) % MOD * b.qpow(b.comb(n + 1, 2), MOD - 2) % MOD, m);
        i64 q = (i * P % MOD + (n + 1) * b.inv[2] % MOD * (1 - P + MOD) % MOD) % MOD;
        ans = (ans + 1ll * i * i % MOD - q * p[i] % MOD + MOD) % MOD;
    }
    printf("%lld", ans * b.qpow(b.comb(n + 1, 2), m) % MOD);
}
