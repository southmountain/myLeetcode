
/*soulution 1:
1、采用hash表，map<int,bool>先将元素放入表中,初始化为false.
2、遍历表中元素，考虑：如果为true,则continue.否则令其值为true,然后分别对当前值i向左右两方向扩展，扩展到的值设为true,确保下次循环到该值时直接跳过
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_map<int,bool> used ;
        for(auto i:nums)
        used[i]=false;
        for(auto i:nums)
        {
            if(used[i])continue;//如果已被标记为true，则跳过
            used[i]=true;
            int length=1;
            for(int j=i+1;used.find(j)!=used.end();j++)
            {
                used[j]=true;
                ++length;
            }
            for(int j=i-1;used.find(j)!=used.end();j--)
            {
                used[j]=true;
                ++length;
            }
            longest=max(length,longest);
        }
        return longest;
    }
};

/*soulution 2:采用 hash表。当新元素n被遍历到时，考虑：
1、是否在表内.如果在，continue.如果不在，考虑n-1,n+1在map中的值，如果找不到，则map[n]=1,否则map[n]=map[n-1]+map[n+1]+1
2、在n-1或n+1有值的情况下，更新n-map[n-1]和n+map[n+1]]的值，即更新两端和本身的值
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_map<int,int> a ;
        for(auto i:nums)
        {
            if(a.find(i)!=a.end())continue;
            int left=0;
            int right=0;
            if(a.find(i-1)!=a.end())
            {
                left=a[i-1];
            }
            if(a.find(i+1)!=a.end())
            {
                right=a[i+1];
            }
            int tmplength=left+right+1;
            longest=max(longest,tmplength);
            a[i]=tmplength;
            if(left!=0)
            a[i-left]=tmplength;
            if(right!=0)
            a[i+right]=tmplength;
        }
        return longest;

    }
};