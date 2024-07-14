// 73) https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colo=1;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0)matrix[0][j]=0;
                    else colo=0;
                }
               
            }
        }
        
        //apart from 0th row and 0 th col as we do it based on them
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if (matrix[i][j] != 0){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                     matrix[i][j]=0;
                    }
              }
            }
        }

        //then oth row
        if(matrix[0][0]==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }

        if(colo==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};

//TC:O(2(M*N))
//SC:O(1)