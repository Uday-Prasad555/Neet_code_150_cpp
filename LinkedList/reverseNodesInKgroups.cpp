class Solution
{
public:
    ListNode *getKth(ListNode *curr, int k)
    {
        while (curr != nullptr && k > 0)
        {
            curr = curr->next;
            k = k - 1;
        }
        return curr;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *groupPrev = dummy;
        while (true)
        {
            ListNode *Kth = getKth(groupPrev, k);
            if (Kth == nullptr)
            {
                break;
            }
            ListNode *groupNext = Kth->next;
            ListNode *prev = Kth->next;
            ListNode *curr = groupPrev->next;
            while (curr != groupNext)
            {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode *temp = groupPrev->next;
            groupPrev->next = Kth;
            groupPrev = temp;
        }
        return dummy->next;
    }
};