class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length=nums.size();
        for(auto i=nums.end()-2;i>=nums.begin();--i)
        {
            if(*(i+1)>*i)
            {
                for(auto j=nums.end()-1;j>=i+1;--j)
                {
                    if(*j>*i)
                    {
                        swap(*j,*i);
                        reverse(i+1,nums.end());
                        return ;
                    }
                }
            }
        }
        reverse(nums.begin(),nums.end());
        return ;
    }
};