class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *curr = second;
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *first = head;
        second = prev;
        while (second != nullptr)
        {
            ListNode *ptr1 = first->next;
            ListNode *ptr2 = second->next;
            first->next = second;
            second->next = ptr1;

            first = ptr1;
            second = ptr2;
        }
    }
};