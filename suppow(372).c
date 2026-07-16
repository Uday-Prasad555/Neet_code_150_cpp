int modpow(int x, int a)
{
    int z = 1;
    x = x % 1337;

    while (a > 0)
    {
        if (a % 2 == 1)
        {
            z = (z * x) % 1337;
        }
        x = (x * x) % 1337;
        a /= 2;
    }
    return z;
}
int superPow(int a, int *b, int bSize)
{
    int result = 1;
    for (int i = 0; i < bSize; i++)
    {
        result = (modpow(result, 10) * modpow(a, b[i])) % 1337;
    }
    return result;
}