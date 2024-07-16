//26. Remove Duplicates from Sorted Array
//TC:O(N)
//SC:O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //brute->hashset
        int i=0;
        int j=1;
        for(j=1;j<nums.size();j++){
            //when they are same->continue;
            //when different
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
