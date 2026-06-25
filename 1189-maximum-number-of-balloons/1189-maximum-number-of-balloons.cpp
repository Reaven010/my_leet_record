class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        for(char c: text){
            m[c]++;
        }
        int total=0;
        while(m['b']>=1 && m['a']>=1 && m['l']>=2 && m['o']>=2 && m['n']>=1){
            total++;
            m['a']--;
            m['b']--;
            m['l']-=2;
            m['o']-=2;
            m['n']--;
        }
        return total;
    }
};