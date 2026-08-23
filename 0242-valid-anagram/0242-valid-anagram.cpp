class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;
        //keep count
        for(char c:s){
            m[c]++;
        }
        for(char c : t){
            m[c]--;
        }
        for(auto [key,val]:m){
            if(m[key]!=0){
                return 0;
            }
        }
        return 1;
    }
};