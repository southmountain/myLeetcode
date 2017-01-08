class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
if (!head)return head;
		RandomListNode*tmp = head;
		while (tmp)
		{
			RandomListNode*a = new RandomListNode(tmp->label);
			a->next = tmp->next;
			tmp->next = a;
			tmp = a->next;
		}
		tmp = head;
		RandomListNode*tmp2;
		while (tmp)
		{
		    if(!tmp->random)
		    {
		        tmp=tmp->next->next;
		    }else
		    {
		        tmp->next->random=tmp->random->next;
		        tmp=tmp->next->next;
		    }
		}
		tmp = head;
		RandomListNode*head2 = head->next;
		while (tmp)
		{
			tmp2 = tmp->next->next;
			tmp->next->next = tmp2?tmp2->next:NULL;
			tmp->next = tmp2;
			tmp = tmp2;
		}
		return head2;

    }
};