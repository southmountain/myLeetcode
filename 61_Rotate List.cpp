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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        ListNode*H=head;
        int len=1;
        while(head->next!=NULL)
        {
            ++len;
            head=head->next;
        }
        head->next=H;
        int num=len-k%len;
        for(int i=0;i<num;i++)
        {
            head=head->next;
        }
        H=head->next;
        head->next=NULL;
        return H;
        
        
    }
};