class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        if(nums.size()<4)return result;
        sort(nums.begin(),nums.end());
        for(int a=0;a<nums.size()-3;a++)
        {
            if(a>0&&nums[a]==nums[a-1])continue;
            for(int b=a+1;b<nums.size()-2;b++)
            {
                if(b>a+1&&nums[b]==nums[b-1])continue;
                int c=b+1;
                int d=nums.size()-1;
                while(c<d)
                {
                    int tmp=nums[a]+nums[b]+nums[c]+nums[d];
                    if(tmp<target)
                    {
                        ++c;
                        while(nums[c]==nums[c-1]&&c<d)++c;
                    }else if(tmp>target)
                    {
                        --d;
                        while(nums[d]==nums[d+1]&&c<d)--d;
                    }else
                    {
                        result.push_back({nums[a],nums[b],nums[c],nums[d]});
                        ++c;
                        --d;
                        while(c<d&&nums[c]==nums[c-1]&&nums[d]==nums[d+1])
                        {
                            ++c;
                            --d;
                        }
                    }
                }
            }
            
        }
        return result;
    }
};