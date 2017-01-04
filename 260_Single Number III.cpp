class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int dif=accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        dif&=-dif;
        vector<int>b(2,0);
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&dif)==0)
            {
                b[0]^=nums[i];
            }else
            {
                b[1]^=nums[i];
            }
        }
        return b;
    }
};