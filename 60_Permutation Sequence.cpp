class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n,'0');
        --k;
        bool b[10]={0};
        for(int i=0;i<n;i++)
        {
            int a=k/jiecheng(n-1-i);
            int j;
            for(j=1;j<=n;j++)
            {
                if(!b[j])
                {
                    if(a==0)break;
                    --a;
                }
            }
            s[i]='0'+j;
            b[j]=1;
            k%=jiecheng(n-1-i);
        }

        return s;
        
    }
    int jiecheng(int n)
    {
        if(n==0)
        return 1;
        return n*jiecheng(n-1);
    }
};