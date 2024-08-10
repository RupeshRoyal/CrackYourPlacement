//merge two into one and sort
//optimal-2 is gap method
//optimal-1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=0;

        while(left>=0 && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;
                right++;
            }
            else break;
        }
        
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.begin()+n);

        for(int i=0;i<n;i++){
            nums1[i+m]=nums2[i];
        }
    
    }
};
// TC:O(NlogN+MlogM+min(n,m));
// SC:O(1)