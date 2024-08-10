//brute search for the element having n>=2 using loops
//hashmap

//moore's Voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int elIndex=0;
        int cnt=1;

        for(int i=1;i<n;i++){
            if(cnt==0){
                elIndex=i;
                cnt=1;
            }else if(nums[i]==nums[elIndex]){
                cnt++;
            }
            else cnt--;
        }

        int vcnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==nums[elIndex]){
                vcnt++;
            }
        }

        if(vcnt>(n/2)){
            return nums[elIndex];
        }

    return -1;
    }
};

//TC:O(N)
//SC:O(1)