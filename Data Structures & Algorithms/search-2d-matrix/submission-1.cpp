class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(),col= matrix[0].size();

        int m=0,n=col-1;

        while(m<row and  n>=0)
        {
            if(matrix[m][n]==target)return true;

            else if(matrix[m][n]<target)
            {
                m+=1;
            }
            else
              n-=1;
        }
        return false;
    }
};
