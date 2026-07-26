class MinStack
{
public:
    int mini;
    vector<int> Stack;
    vector<int> minStack;
    int topIndex;
    MinStack()
    {
        topIndex = -1;
    }

    void push(int value)
    {
        if (minStack.empty())
        {
            minStack.push_back(value);
        }
        else
        {
            minStack.push_back(min(value, minStack.back()));
        }
        Stack.push_back(value);
        topIndex = topIndex + 1;
    }

    void pop()
    {
        Stack.pop_back();
        minStack.pop_back();
        topIndex = topIndex - 1;
    }

    int top()
    {
        return Stack[topIndex];
    }

    int getMin()
    {
        return minStack[topIndex];
    }
};