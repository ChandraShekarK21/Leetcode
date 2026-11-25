class Solution {
public:
    const long long mod = 1000000007;
    bool check(vector<int>& nums,int size,long long base){
        int n=nums.size();
        int i=0,j=0;
        long long hash=0;
        unordered_map<long long,int> mp;
        long long p = 1;
        //
        for(int x = 1; x < size; x++){
            p = (p * base) % mod;
        }
        while(j<n){
            hash=(hash*base+nums[j])%mod;
            if((j-i+1)<size){
                j++;
            }
            else{
                mp[hash]++;
                hash=(hash-p*nums[i] % mod + mod)%mod;
                i++;
                j++;
            }
        }
        for(auto x:mp){
            if(x.second == 1){
                return true;
            }
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        long long base = (long long)*max_element(nums.begin(), nums.end()) + 1;
        int l=1,r=n;
        int ans=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,mid,base)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }



};