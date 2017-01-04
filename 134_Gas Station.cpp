class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0;
        int total=0;
        int j=0;
        for(int i=0;i<=n-1;i++)
        {
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0)
            {
                j=i+1;
                sum=0;
            }
        }
        return total>=0?j:-1;
    }
};