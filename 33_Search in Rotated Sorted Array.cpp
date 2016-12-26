class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first=0,end=nums.size();
        while(first!=end)
        {
            int mid=first+(end-first)/2;
            if(nums[mid]==target)
            return mid;
            if(nums[mid]<nums[first])//mid在后半段sorted array
            {
                //判断target是否在后半段里，否则舍弃后半段
                if(nums[mid]<target&&target<=nums[end-1])
                {
                    first=mid+1;
                }else{
                    end=mid;
                }
            }else{
                //mid在前半段sorted array
                //判断target是否在前半段，否则舍弃前半段
                if(nums[mid]>target&&target>=nums[first])
                {
                    end=mid;
                }else{
                    first=mid+1;
                }
            }
            
        }
        return -1;
    }
};