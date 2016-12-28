/*
先排序，然后左右逼近，关键在于排除重复项。

*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        const int target=0;
        if(nums.size()<3)return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            if(i>0&&nums[i]==nums[i-1])continue;
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]<target)
                {
                    ++j;
                    while(nums[j]==nums[j-1]&&j<k)++j;
                }else if(nums[i]+nums[j]+nums[k]>target)
                {
                    --k;
                    while(nums[k]==nums[k+1]&&j<k)--k;
                }else{
                    result.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                    while(nums[j]==nums[j-1]&&nums[k]==nums[k+1]&&j<k)
                    {
                        ++j;
                        --k;
                    }
                }
            }
        }
        return result;
    }
};