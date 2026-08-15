class Solution {
public:
    ListNode* merge(ListNode* L1, ListNode* L2){
        ListNode* dummy= new ListNode(-1);
        ListNode* tail = dummy;
        while (L1 != nullptr && L2 != nullptr){
            if(L1->val <= L2->val){
                tail->next=L1;
                L1=L1->next;
                tail=tail->next;
            }
            else{
                tail->next=L2;
                L2=L2->next;
                tail=tail->next;
            }
        }
        if(L1 != nullptr){
            tail->next=L1;
        }
        else{
            tail->next=L2;
        }
        return dummy->next;
    }
    ListNode* mergeRange(vector<ListNode*>& lists, int l, int r){
        if(l==r){
            return lists[l];
        }
        int mid=l+(r-l)/2;
        ListNode* left=mergeRange(lists,l,mid);
        ListNode* right=mergeRange(lists,mid+1,r);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        return mergeRange(lists, 0, lists.size() - 1);
        
    }
};