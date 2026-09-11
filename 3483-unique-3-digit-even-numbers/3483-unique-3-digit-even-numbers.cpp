class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int>s;
        for (int i =0;i<digits.size();i++){
            for(int j =0;j<digits.size();j++){
                if(i==j){
                    continue;
                }
                for(int k =0;k<digits.size();k++){
                    if(j==k || i==k){
                        continue;
                    }
                    int num=digits[i]*100 + digits[j]*10+digits[k];
                    if(digits[i]==0){
                        continue;
                    }
                    if(num%2==0){
                        s.insert(num);
                    }
                }
            }
        }
        return s.size();
    }
};