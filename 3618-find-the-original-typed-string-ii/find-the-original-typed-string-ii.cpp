class Solution {
    int MOD = 1e9+7;
public:
    int possibleStringCount(string word, int k) {
       
        int n = word.size();
        vector<int> runs(1,1);
        for(int i=1;i<n;++i){
            if(word[i]==word[i-1])  runs.back()++;
            else                    runs.push_back(1);
        }
       
        int total_combinations = 1;
        for(int freq: runs)
            total_combinations = (1LL * total_combinations * freq) % MOD;
        
        if(runs.size()>=k)
            return total_combinations;



    // these things needs to be write cause when i revise these then i have to watch 1hr long video, so by seeing it i can understand fast and make my intuitions

        /*
            count[i]=x for 3rd run means: 'x' number of strings can be formed of length 'i',
                                        using the first 3 runs.
        */
        vector<int> count(k), newCount(k), prefix_sum(k);
        count[0] = 1;

        // Count number of strings of different sizes formed by including all runs
        for(int freq: runs){
            //Update Prefix_sum array
            prefix_sum[0] = count[0];
            for(int i=1;i<k;++i)
                prefix_sum[i] = (prefix_sum[i-1] + count[i]) % MOD;
            
            //Make a new run
            for(int i=1;i<k;++i){
                int right = prefix_sum[i-1];
                int left = 0;
                if(i-1-freq >= 0)
                    left = prefix_sum[i-1-freq];
                newCount[i] = (right - left + MOD) % MOD;
            }
            swap(count,newCount);
            fill(newCount.begin(),newCount.end(),0);
        }
        int invalid_combinations = 0;
        for(int i=0;i<k;++i)
            invalid_combinations = (invalid_combinations + count[i]) % MOD;

        return (total_combinations - invalid_combinations + MOD) % MOD;
    }
};

// do this question again after one month so that you will be clear of all doubts and make your own intuitions