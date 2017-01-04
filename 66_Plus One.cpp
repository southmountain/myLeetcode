class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=digits.size();
        int jingwei=1;
        for(int i=size-1;i>=0;i--)
        {
            if(digits[i]!=9)
            {
                ++digits[i];
                return digits;
            }
            if(i!=0)
            {
                digits[i]=0;
            }else{
                digits[i]=0;
                digits.insert(digits.begin(),1);
            }
        }
        return digits;
    }
};