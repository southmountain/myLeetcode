
#include "NeedHeader.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>a;
        int maxsize=0;
        int start=0;
        
        for(int last=0;last<s.size();last++)
        {
            auto pos=a.find(s[last]);
            if(pos!=a.end()&&pos->second>=start)
            {
                maxsize=max(maxsize,last-start);
                start=a[s[last]]+1;
            }
            a[s[last]]=last;
        }
        return max(maxsize,(int)s.size()-start);
    }
};