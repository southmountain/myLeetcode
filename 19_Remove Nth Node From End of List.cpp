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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        int len=1;
        ListNode* H=head;
        while(head->next!=NULL)
        {
            head=head->next;
            ++len;
        }
        head=H;
        int num=len-n%len-1;
        if(num==len-1)
        {
            ListNode*tmp=head->next;
            delete head;
            return tmp;
        }
        for(int i=0;i<num;i++)
        {
            head=head->next;
        }
        ListNode*tmp=head->next;
        head->next=tmp->next;
        delete tmp;
        return H;
            
    }
};