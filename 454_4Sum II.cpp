class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int>m1,m2;
        initialmap(A,B,m1);
        initialmap(C,D,m2);
        int count=0;
        for(auto t=m1.begin();t!=m1.end();++t)
        {
            auto r=m2.find(-t->first);
            if(r!=m2.end())
            {
                count+=t->second*r->second;
            }
        }
        return count;
    }
private:
    void initialmap(vector<int>&X,vector<int>&Y,unordered_map<int,int>&m)
    {
        for(int x=0;x<X.size();x++)
        for(int y=0;y<Y.size();y++)
        {
            ++m[X[x]+Y[y]];
        }
    }
};