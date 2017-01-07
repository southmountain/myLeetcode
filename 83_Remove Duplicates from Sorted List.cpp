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
        set<int>a;
        ListNode dummy=ListNode(-1);
        dummy.next=head;
        ListNode*prev=&dummy;
        while(head!=NULL)
        {
            if(a.find(head->val)!=a.end())
            {
                prev->next=head->next;
                delete head;
                head=prev->next;
            }else
            {
                a.insert(head->val);
                prev=head;
                head=head->next;
            }
        }
        return dummy.next;
    }
};