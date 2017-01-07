/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next||k<2)return head;
        ListNode*first=head;
        for(int i=0;i<k-1;i++)
        {
            first=first->next;
            if(!first)
            return head;
            
        }
        ListNode*second=reverseKGroup(first->next,k);
        ListNode*prev=head;
        ListNode*cur=head->next;
        prev->next=second;
        while(cur!=first)
        {
            ListNode*next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        cur->next=prev;
        return cur;
        
    }
};