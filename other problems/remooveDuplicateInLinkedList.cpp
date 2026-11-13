class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
            while (curr->next != nullptr && curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};