#include <cstddef>
#include <vector>

typedef long long i64;
namespace OI_math
{
    template<size_t SIZE, i64 MOD>
    struct Base
    {
        i64 frc[SIZE + 5], ifrc[SIZE + 5], inv[SIZE + 5], mu[SIZE + 5], phi[SIZE + 5], drgm[SIZE + 5], ctl[SIZE + 5];
        bool isp[SIZE + 5], _vis[SIZE + 5];
        std::vector <i64> pri;

        Base()
        {
            mu[1] = frc[0] = ifrc[0] = inv[0] = 1;
            for (int i = 1; i < SIZE; ++i)
            {
                frc[i] = frc[i - 1] * i % MOD;
            }
            ifrc[SIZE - 1] = qpow(frc[SIZE - 1], MOD - 2);
            for (int i = SIZE - 2; i >= 1; --i)
            {
                ifrc[i] = ifrc[i + 1] * (i + 1) % MOD;
            }
            for (int i = 1; i < SIZE; ++i)
            {
                inv[i] = ifrc[i] * frc[i - 1] % MOD;
            }
            for (int i = 1; i < SIZE; ++i)
            {
                drgm[i] = (i * drgm[i - 1] + ((i & 1) ? -1 : 1)) % MOD;
            }
            for (int i = 1; i < SIZE; i++)
            {
                ctl[i] = ctl[i - 1] * (4 * (i64)i - 2) % MOD * inv[i + 1] % MOD;
            }
            for (int i = 2; i < SIZE; ++i)
            {
                if (!_vis[i])
                {
                    mu[i] = -1;
                    phi[i] = i - 1;
                    isp[i] = true;
                    pri.push_back(i);
                }
                for (i64 j : pri)
                {
                    if (i * j > SIZE)
                    {
                        break;
                    }
                    _vis[i * j] = true;
                    if (i % j == 0)
                    {
                        mu[i * j] = 0;
                        phi[i * j] = phi[i] * j;
                        break;
                    }
                    mu[i * j] = -mu[i];
                    phi[i * j] = phi[i] * phi[j];
                }
            }
        }

        i64 qpow(i64 a, i64 x)
        {
            i64 res = 1;
            while (x)
            {
                if (x & 1)
                {
                    res = res * a % MOD;
                }
                a = a * a % MOD;
                x >>= 1;
            }
            return res;
        }

        i64 comb(i64 x, i64 y)
        {
            return frc[x] * ifrc[y] % MOD * ifrc[x - y] % MOD;
        }

        i64 comb_lcs(i64 x, i64 y)
        {
            if (x < MOD && y < MOD)
            {
                return frc[x] * ifrc[y] % MOD * ifrc[x - y] % MOD;
            }
            return comb_lcs(x / MOD, y / MOD) * comb_lcs(x % MOD, y % MOD) % MOD;
        }
    };

    template<size_t N, size_t M, i64 MOD>
    struct Base_2d
    {
        Base<std::max(N, M) + 5, MOD> bs;
        i64 strl1[N + 5][M + 5], strl2[N + 5][M + 5], prt[N + 5][M + 5];

        Base_2d()
        {
            strl1[0][0] =  strl2[0][0] = 1;
            for (int i = 1; i < N; ++i)
            {
                for (int j = 0; j <= i && j < M; ++j)
                {
                    strl1[i][j] = (strl1[i - 1][j - 1] + (i - 1) * strl2[i - 1][j] % MOD) % MOD;
                    strl2[i][j] = (strl2[i - 1][j - 1] + j * strl2[i - 1][j] % MOD) % MOD;
                }
                for (int j = 1; j <= i && j < M; ++j)
                {
                    prt[i][j] = (prt[i - j][j] + prt[i - 1][j - 1]) % MOD;
                }
            }
        }
    };
}
