# oi-lib

## math
### all.hpp
导入 `math` 下 的全部头文件

### base.cpp

#### Base
``` cpp
Base <SIZE, MOD> base;
// 创建模数为 MOD，数组大小为 SIZE 的基本数学工具集合
// MOD 应为质数
```

| 数组 | 释义 |
| ---- | ---- |
| `inv[x]`  | x 在模 $MOD$ 意义下的逆元 |
| `frc[x]`  | 模 $MOD$ 意义下 x 的阶乘 |
| `ifrc[x]` | 模 $MOD$ 意义下 x 阶乘的逆元 |
| `mu[x]`   | 模 $MOD$ 意义下 $\mu(x)$ |
| `phi[x]`  | 模 $MOD$ 意义下 $\phi(x)$ |
| `drgm[x]` | 模 $MOD$ 意义下[错排数](https://oeis.org/A000166)第 x 项 |
| `ctl[x]`  | 模 $MOD$ 意义下[卡特兰数](https://oeis.org/A000108)第 x 项 |

| 函数 | 释义 | 备注 |
| ---- | ---- | ---- |
| `qpow(i64 a, i64 x)`     | 模 $MOD$ 意义下 $a^x$ | 复杂度 $O(\log x)$ |
| `comb(i64 n, i64 m)`     | 模 $MOD$ 意义下 ${n}\choose{m}$ | $n, m$ 应小于 `SIZE` |
| `comb_lcs(i64 n, i64 m)` | 模 $MOD$ 意义下 ${n}\choose{m}$ | 利用卢卡斯定理实现 |

#### Base
``` cpp
Base <N, M, MOD> base;
// 创建模数为 MOD，方阵大小为 N $\times$ M 的基本二维数学工具集合
// MOD 应为质数
```

| 数组 | 释义 |
| ---- | ---- |
| `strl1[x][y]` | 第一类斯特林数 $x \brack y$ |
| `strl2[x][y]` | 第一类斯特林数 $x \brace y$ |
| `prt[x][y]`   | k-分拆数 $p(n, k)$ |
