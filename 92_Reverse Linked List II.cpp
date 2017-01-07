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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*prev=dummy;
        for(int i=1 ;i<m;i++)
            prev=prev->next;
        ListNode*_m=prev;
        prev=prev->next;
        ListNode*cur=prev->next;
        for(int i=m;i<n;i++)
        {
            prev->next=cur->next;
            cur->next=_m->next;
            _m->next=cur;
            cur=prev->next;
        }
        return dummy->next;
    }
        
};