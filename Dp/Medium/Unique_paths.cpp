class Solution {
public:
    int uniqueFunc(int i,int j,vector<vector<int>>& dp){
        if(i==0&&j==0) return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int up=uniqueFunc(i-1,j,dp);
        int left=uniqueFunc(i,j-1,dp);

        return dp[i][j]=up+left;

    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return uniqueFunc(m-1,n-1,dp);

        // int dp[m][n];
        // // dp[0][0]=1;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0&&j==0) {
        //             dp[0][0]=1;
        //         }
        //         else{
        //             int up=0;
        //             int left=0;
        //             if(i>0) up=dp[i-1][j];
        //             if(j>0) left=dp[i][j-1];
        //             dp[i][j]=up+left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int> prev(n,0);

        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0) {
                    temp[j]=1;
                }
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=up+left;
                }
            }
            prev=temp;
        }
        return prev[n-1];


    }
};