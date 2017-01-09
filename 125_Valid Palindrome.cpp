class Solution {
public:
    bool isPalindrome(string s) {
        for(auto& c:s)
        {
            c=tolower(c);
        }
        auto left=s.begin(),right=s.end()-1;
        while(left<right)
        {
            if(!isalnum(*left))++left;
            else if(!isalnum(*right))--right;
            else if(*left!=*right)return false;
            else{
                ++left;
                --right;
            }
        }
        return true;
    }
};