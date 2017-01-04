class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        set<int>row;
        set<int>col;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
        }
        for(int i=0;i<m;i++)
        {
            if(row.find(i)!=row.end())
            {
                fill(matrix[i].begin(),matrix[i].end(),0);
            }
        }
        for(int j=0;j<n;j++)
        {
            if(col.find(j)!=col.end())
            {
                for(int i=0;i<m;i++)
                matrix[i][j]=0;
            }
        }
        
    }
};