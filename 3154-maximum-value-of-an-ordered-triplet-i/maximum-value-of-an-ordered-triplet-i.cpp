class Solution {
    #define ll long long
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n =  nums.size();
       
        vector<int> right_max(n);
        int max_val = nums[n-1];
        for(int i=n-2;i>0;--i){
            right_max[i] = max_val;
            max_val = max(max_val,nums[i]);
        }

        ll max_triplet = 0;
        max_val = nums[0];
        for(int i=1;i<n-1;++i){
            max_triplet = max<ll>(max_triplet,(1LL*max_val-nums[i])*right_max[i]);
            max_val = max(max_val,nums[i]);
        }
        return max_triplet;
    }
};
