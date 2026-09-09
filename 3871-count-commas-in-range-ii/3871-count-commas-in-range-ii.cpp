class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        for (long long p = 1; ; p++) {
            long long start = 1;
            
            for (int i = 0; i < 3 * p; i++)
                start *= 10;
            
            if (start > n)
                break;
            
            long long end = start * 1000 - 1;
            
            long long count = min(n, end) - start + 1;
            ans += count * p;
        }
        
        return ans;
    }
};