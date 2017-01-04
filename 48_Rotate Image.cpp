
//先沿竖直中线反转，再沿45度对角线反转。
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        for(int i=0;i<=n-2;i++)
        for(int j=0;j<=n-2-i;j++)
        {
            int tmp=matrix[i][j];
            matrix[i][j]=matrix[n-1-j][n-1-i];
            matrix[n-1-j][n-1-i]=tmp;
        }
        
        
    }
};