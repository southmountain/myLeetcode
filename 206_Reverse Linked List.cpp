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
    ListNode* reverseList(ListNode* head) {
        ListNode* r=NULL;
        while(head!=NULL)
        {
            ListNode*tmp=new ListNode(head->val);
            head=head->next;
            tmp->next=r;
            r=tmp;
        }
        return r;
    }
};