class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n = matrix[0].size();
        int i=m-1 , j=0;

        while( i>=0 && j<n){
            int cell= matrix[i][j];

            if(cell==target){
                return true;
            }else if(cell>target){
               i--;
            }else if (cell < target){
                j++;
            }
               
        
        }
         return false;
            
        
    }
};