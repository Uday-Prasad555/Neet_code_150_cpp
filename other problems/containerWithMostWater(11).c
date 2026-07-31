int maxArea(int *height, int heightSize)
{
    int init = 0;
    int fin = heightSize - 1;
    int heightt;
    int area = 0;
    int dist;
    for (int i = 0; i < heightSize - 1; i++)
    {
        dist = fin - init;
        if (height[init] > height[fin])
        {
            heightt = height[fin];
            fin = fin - 1;
        }
        else
        {
            heightt = height[init];
            init = init + 1;
        }
        if (area < dist * heightt)
        {
            area = dist * heightt;
        }
    }
    return area;
}