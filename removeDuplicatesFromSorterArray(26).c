int removeDuplicates(int *nums, int numsSize)
{
    int pointer = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[pointer] != nums[i])
        {
            pointer++;
            nums[pointer] = nums[i];
        }
    }
    return pointer + 1;
}