
#include "NeedHeader.h"
class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxlength=0;
        for(int i=0;i<s.size();i++)
        {
            int len1=lengthPalindrome(s,i,i);
            int len2=lengthPalindrome(s,i,i+1);
            int maxlen=max(len1,len2);
            if(maxlen>maxlength)
            {
                maxlength=maxlen;
                start=i-(maxlen-1)/2;
            }
        }
        return s.substr(start,maxlength);
    }
private:
    int lengthPalindrome(string&s,int l,int r)
    {
        while(l>=0&&r<s.size()&&s[l]==s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }
};