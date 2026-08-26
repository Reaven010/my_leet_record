class Solution {
public:
    bool ispalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return 0;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maximum=INT_MIN,start=0,end=0,prev=0;
        string ans;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
                    prev=maximum;
                    maximum=max(maximum,j-i+1);
                    if(prev!=maximum){
                        start=i;
                        end=j;
                    }
                }
            }
        }
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
    }
};