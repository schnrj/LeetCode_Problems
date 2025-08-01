class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
    long long splitArray(vector<int>& nums) {

       long long sum1=0,sum2=0;
        for(int i=0;i<nums.size();i++){
            if(isPrime(i)){
                sum1+=nums[i];
            }
            else sum2+=nums[i];
        }
        return abs(sum1-sum2);
    }
};