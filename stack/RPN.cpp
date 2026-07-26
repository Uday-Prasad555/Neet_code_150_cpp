class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int a, b, c, d, n;
        stack<int> pn;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                a = pn.top();
                pn.pop();
                b = pn.top();
                pn.pop();
                n = b + a;
                pn.push(n);
            }
            else if (tokens[i] == "-")
            {
                a = pn.top();
                pn.pop();
                b = pn.top();
                pn.pop();
                n = b - a;
                pn.push(n);
            }
            else if (tokens[i] == "/")
            {
                a = pn.top();
                pn.pop();
                b = pn.top();
                pn.pop();
                n = b / a;
                pn.push(n);
            }
            else if (tokens[i] == "*")
            {
                a = pn.top();
                pn.pop();
                b = pn.top();
                pn.pop();
                n = b * a;
                pn.push(n);
            }
            else
            {
                d = stoi(tokens[i]);
                pn.push(d);
            }
        }
        return pn.top();
    }
};