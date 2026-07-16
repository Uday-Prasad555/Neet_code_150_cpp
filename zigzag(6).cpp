class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1 || numRows >= s.size())
            return s;

        string ans;
        int n = s.size();
        int cycle = 2 * numRows - 2;

        for (int row = 0; row < numRows; row++)
        {

            int j = row;

            int gap1 = cycle - 2 * row;
            int gap2 = 2 * row;

            bool useGap1 = true;

            while (j < n)
            {

                ans += s[j];

                if (row == 0 || row == numRows - 1)
                {
                    j += cycle;
                }
                else
                {

                    if (useGap1)
                        j += gap1;
                    else
                        j += gap2;

                    useGap1 = !useGap1;
                }
            }
        }

        return ans;
    }
};