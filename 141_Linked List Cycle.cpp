class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode*walk=head;
        ListNode*run=head;
        while(run->next&&run->next->next)
        {
            walk=walk->next;
            run=run->next->next;
            if(walk==run)return true;
        }
        return false;
    }
};