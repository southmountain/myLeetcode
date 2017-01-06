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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>a1,a2;
        while(l1!=NULL)
        {
            a1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            a2.push(l2->val);
            l2=l2->next;
        }
        ListNode*result=NULL;
        int carry=0;
        while(!a1.empty()||!a2.empty())
        {
            int v1,v2;
            if(a1.empty())
            {
                v1=0;
            }else
            {
                v1=a1.top();
                a1.pop();
            }
            if(a2.empty())
            {
                v2=0;
            }else
            {
                v2=a2.top();
                a2.pop();
            }
            int num=v1+v2+carry;
            if(num>9)
            {
                carry=1;
                num-=10;
            }else
            {
                carry=0;
            }
            ListNode*tmp=new ListNode(num);
            tmp->next=result;
            result=tmp;
        }
        if(carry==1)
        {
            ListNode*tmp=new ListNode(carry);
            tmp->next=result;
            result=tmp;
        }
        return result;
    }
};