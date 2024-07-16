// Type-II) whether 2 sum exists or not
//TC:O(N+NLOGN)
//SC:O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int left=0;
        int n=nums.size();
        int right=n-1;

        sort(nums.begin(),nums.end());

        while(left<=right){
            if(nums[left]+nums[right] < target)left++;
            else if(nums[left]+nums[right]>target)right--;
            else return true;
        }

        return false;
    }
};

//Type-1 return the indexes of the 2 sum elements using map
//TC:O(N)
//SC:O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        unordered_map <int,int> mpp;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int rem=target-curr;
            if(mpp.find(rem)!=mpp.end()){
                return {i,mpp[rem]};
            }
            else mpp[curr]=i;
        }

        return {-1,-1};


    }
};


