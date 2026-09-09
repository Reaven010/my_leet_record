class Solution {
public:
    int countCommas(int n) {
        int count =0;
        if(n<1000){
            return 0;
        }
        else if(n>=1000 && n<10000){
            for (int i=1000;i<=n;i++){
                count++;
            }
        }
        else if (n>=10000 && n<100000){
            count+=9000;
            for(int i=10000;i<=n;i++){
                count++;
            }
        }
        else if(n>=100000 && n<1000000){
            count+=99000;
            for(int i=100000;i<=n;i++){
                count++;
            }
        }
        return count;
    }
};