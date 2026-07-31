struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *L3, *temp, *temp1, *temp2;
    L3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = L3;
    temp1 = l1;
    temp2 = l2;

    int c = 0;
    int data;
    int k;

    while (temp1 != NULL || temp2 != NULL)
    {

        data = c;

        if (temp1 != NULL)
        {
            data += temp1->val;
            temp1 = temp1->next;
        }

        if (temp2 != NULL)
        {
            data += temp2->val;
            temp2 = temp2->next;
        }

        k = data % 10;
        c = data / 10;

        temp->val = k;

        if (temp1 != NULL || temp2 != NULL)
        {
            temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp = temp->next;
        }
    }

    if (c != 0)
    {
        temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = c;
    }

    temp->next = NULL;
    return L3;
}