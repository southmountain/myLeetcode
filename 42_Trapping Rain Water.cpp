class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        if(size<=2)return 0;
        int maxheight=-1,maxId=0;
        for(int i=0;i<size;i++)
        {
            if(height[i]>maxheight)
                {
                    maxheight=height[i];
                    maxId=i;
                }
        }
        int area=0;
        int tmp=0;
        for(int i=0;i<maxId;i++)
        {
            if(height[i]>tmp)
            {
                tmp=height[i];
            }else
            {
                area+=tmp-height[i];
            }
        }
        tmp=0;
        for(int i=size-1;i>maxId;i--)
        {
            if(height[i]>tmp)
            {
                tmp=height[i];
            }else
            {
                area+=tmp-height[i];
            }
        }
        return area;
        
    }
};