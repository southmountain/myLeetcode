#include "NeedHeader.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        for(int l=0,r=height.size()-1;l!=r; )
        {
            int square=(r-l)*min(height[l],height[r]);
            area=max(area,square);
            if(height[l]<=height[r])
            {
                l++;
            }else{
                r--;
            }
        }
        return area;
    }
};