double myPow(double x, int n)
{
    double z = 1;
    long long N = n;
    if (N < 0)
    {
        N = -N;
        x = 1 / x;
    }
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            z *= x;
        }
        x *= x;
        N /= 2;
    }
    return z;
}