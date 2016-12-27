//相比于rotated sorted array 多考虑当nums[mid]==nums[first]的情况
class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int first=0,end=nums.size();
         while(first!=end)
         {
             int mid=first+(end-first)/2;
             if(nums[mid]==target)
             return true;
             if(nums[mid]<nums[first])
             {
                 if(target>nums[mid]&&target<=nums[end-1])
                 first=mid+1;
                 else
                    end=mid;
                 
             }else if(nums[mid]>nums[first])
             {
                 if(target>=nums[first]&&target<nums[mid])
                 end=mid;
                 else
                 first=mid+1;
                 
             }else
             {
                 first++;
             }
             
         }
         return false;
    }
};