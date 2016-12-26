/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include "NeedHeader.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*start=new ListNode(0);
        int a;
        int b=0;
        ListNode*tmp=start;
        while(l1!=NULL||l2!=NULL)
        {
            int x=(l1!=NULL)?l1->val:0;
            int y=(l2!=NULL)?l2->val:0;
            a=x+y+b;
            b=(a>9)?1:0;
            a=a%10;
            start->next=new ListNode(a);
            start=start->next;
            l1=(l1!=NULL)?l1->next:l1;
            l2=(l2!=NULL)?l2->next:l2;
        }
        if(b==1)
        {
            start->next=new ListNode(b);
        }
        return tmp->next;
        
    }
};