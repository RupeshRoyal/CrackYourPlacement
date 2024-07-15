// 121)https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int diff;

        for(int i=0;i<arr.size();i++){
            mini=min(mini,arr[i]);
            diff=arr[i]-mini;
            maxi=max(maxi,diff);
        }
        return maxi;
    }
    
};

// TC:O(N)
// SC:O(1)