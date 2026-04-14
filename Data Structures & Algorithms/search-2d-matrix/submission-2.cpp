class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(),col= matrix[0].size();

        int l=0,h=row*col-1;

        while(l<=h)
        {
            int mid = l+(h-l)/2;

            int m = mid / col;
            int n = mid%col;

            if(matrix[m][n]==target)return true;

            if(matrix[m][n]<target)l=mid+1;
            else
             h=mid-1;
        }
        return false;
    }
};
