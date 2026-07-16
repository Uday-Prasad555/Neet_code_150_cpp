int findClosest(int x, int y, int z)
{
    int d1 = x - z;
    int d2 = y - z;
    if (d1 < 0)
    {
        d1 = 0 - d1;
    }
    if (d2 < 0)
    {
        d2 = 0 - d2;
    }
    if (d1 < d2)
    {
        return 1;
    }
    else if (d1 > d2)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}