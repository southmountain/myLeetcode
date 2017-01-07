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
    ListNode* partition(ListNode* head, int x) {
        ListNode*left=new ListNode(-1);
        ListNode*right=new ListNode(-1);
        ListNode*l=left;
        ListNode*r=right;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                left->next=head;
                left=left->next;
            }else
            {
                right->next=head;
                right=right->next;
            }
            head=head->next;
        }
        left->next=r->next;
        right->next=NULL;
        return l->next;
    }
};