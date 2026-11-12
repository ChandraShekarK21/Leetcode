class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int icount=1,dcount=1,res=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                icount++;
            }
            else{
                icount=1;
            }
            res=max(res,icount);

        }
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                dcount++;
            }
            else{
                dcount=1;
            }
            res=max(res,dcount);
        }
        return res;
    }
};