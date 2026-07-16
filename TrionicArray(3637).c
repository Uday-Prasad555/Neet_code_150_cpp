bool isTrionic(int *nums, int numsSize)
{
    int c = 0;
    if (numsSize < 3)
    {
        return false;
    }
    if (nums[0] > nums[1] || nums[numsSize - 1] < nums[numsSize - 2])
    {
        return false;
    }
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (i != 0 && i < numsSize - 1)
        {
            if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i])
            {
                c = c + 1;
            }
            else if (nums[i - 1] > nums[i] && nums[i + 1] > nums[i])
            {
                c = c + 1;
            }
        }
        if (nums[i] == nums[i + 1])
        {
            return false;
        }
    }
    if (c == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}