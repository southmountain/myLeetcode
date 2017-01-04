class Solution {
public:
    int climbStairs(int n) {
        int prev=1;
        int cur=1;
        if(n==1)
        return cur;
        for(int i=2;i<=n;i++)
        {
            int tmp=cur;
            cur+=prev;
            prev=tmp;
        }
        return cur;
    }
};