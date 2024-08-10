//memoization
class Solution {
public:

    int sumFunc(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(i==0&&j==0) return grid[0][0];
        if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];

        int up=grid[i][j]+sumFunc(i-1,j,dp,grid);
        int left=grid[i][j]+sumFunc(i,j-1,dp,grid);

        return dp[i][j]=min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>> dp(m, vector<int>(n, -1));
        return sumFunc(m-1,n-1,dp,grid);

    }
};

//tabulation

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>> dp(m, vector<int>(n, -1));
        // return sumFunc(m-1,n-1,dp,grid);
        
        //tabulation
        // dp[0][0]=grid[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 &&j==0)dp[0][0]=grid[0][0];
                else{
                    // if(i<0||j<0) dp[i][j]=1e9;

                int up=grid[i][j],left=grid[i][j];

                if(i>0) up+=dp[i-1][j];
                else up +=1e9;
                if(j>0) left+=dp[i][j-1];
                else left+=1e9;

                dp[i][j]=min(up,left);
                } 
           }
        }

        return dp[m-1][n-1];
    }
};


        //~~~~~~~~space optimization
        int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prev(n, -1);

        for(int i=0;i<m;i++){
            vector<int> temp(n, -1);//curr row
            for(int j=0;j<n;j++){
                if(i==0 &&j==0)prev[0]=grid[0][0];
                else{
                // if(i<0||j<0) dp[i][j]=1e9;
                int up=grid[i][j],left=grid[i][j];

                if(i>0) up+=prev[j];
                else up +=1e9;
                if(j>0) left+=temp[i][j-1];
                else left+=1e9;

                
                } 
           }
        }

        return prev[m-1];
    }
