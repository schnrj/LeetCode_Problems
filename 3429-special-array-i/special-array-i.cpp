class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]+nums[i-1])%2==0) return false;
        }
        return true;
    }
};