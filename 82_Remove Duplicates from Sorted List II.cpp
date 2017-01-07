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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode*p=head->next;
        if(p->val==head->val)
        {
            while(p&&p->val==head->val)
            {
                head->next=p->next;
                delete p;
                p=head->next;
            }
            delete head;
            return deleteDuplicates(p);
        }else
        {
            head->next=deleteDuplicates(p);
            return head;
        }
    }
};