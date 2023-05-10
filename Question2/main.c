#include <string.h>

/*
    First Way: matrix exponentiation
*/

void multiply1(long long a[3][3], long long b[3][3])
{
    long long mul[3][3];
    memset(mul, 0, sizeof(mul));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
                mul[i][k] += a[i][j] * b[j][k];
        }
    }

    // storing the multiplication result in a[][]
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = mul[i][j]; // Updating our matrix
}

long long multiply2(long long a[3][3], long long b[3][1])
{
    long long mul[3][1];
    memset(mul, 0, sizeof(mul));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 1; k++)
                mul[i][k] += a[i][j] * b[j][k];
        }
    }

    return mul[2][0];
}

long long power(int n)
{
    long long F[3][3] = {{0, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    long long M[3][1] = {{2}, {1}, {0}};
    long long res[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    for (int i = 0; (1ll << i) <= n; i++)
    {
        if ((n & (1ll << i)) != 0)
        {
            multiply1(res, F);
        }
        multiply1(F, F);
    }

    return multiply2(res, M);
}

long long F1(int n)
{
    return power(n);
}

/*
 Second Way: dp with optimized space
 */

long long F2(int n)
{
    if (n >= 0 && n <= 2)
        return n;

    long long dp[3];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        long long tmp = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = tmp;
    }

    return dp[2];
}

/*
 Third Way: Recursive
 */

long long F3(int n)
{
    if (n >= 0 && n <= 2)
        return n;
    return F3(n - 2) + F3(n - 3);
}
