/*
加了个哈希表保存每次差值对应的值，最后返回最小的那个值
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return target;
        sort(nums.begin(),nums.end());
        int compare=INT_MAX;
        unordered_map<int,int>result;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int tmp=nums[i]+nums[j]+nums[k]-target;
                compare=min(compare,abs(tmp));
                result[abs(tmp)]=tmp+target;
            if(tmp<0)
            {
                j++;
                while(nums[j]==nums[j-1]&&j<k)j++;
            }else if(tmp>0)
            {
                k--;
                while(nums[k]==nums[k+1]&&j<k)k--;
            }else
            {
                return target;
            }
            }
            
        }
        return result[compare];
    }
};