#include "NeedHeader.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
        return nums.size();
        int index=2;                    
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]!=nums[index-2])         //只与nums数组第前2个比较
            {
                nums[index++]=nums[i];
            }
        }
        return index;
        
    }
};