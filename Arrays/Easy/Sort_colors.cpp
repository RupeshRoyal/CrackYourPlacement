//75) sort colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort
        //no of 0,1,2
        //dutch national flag algorithm ??
        int c1=0;
        int c2=0;
        int c0=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==0)c0++;
            else if(nums[i]==1)c1++;
            else if(nums[i]==2)c2++;
        }

        for(int i=0;i<c0;i++){
            nums[i]=0;
        }
        for(int i=c0;i<c1+c0;i++){
            nums[i]=1;
        }
        for(int i=c1+c0;i<n;i++){
            nums[i]=2;
        }
       
    }
};
