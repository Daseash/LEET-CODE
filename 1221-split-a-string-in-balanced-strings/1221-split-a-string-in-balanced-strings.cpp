class Solution {
public:
    int balancedStringSplit(string s) {
        int ans =0;
        int countL=0;
        int countR=0;

        for(int i = 0 ; i < s.size(); i++){

            if (s[i]=='L'){
                countL++;
            }else{
                countR++;
            }

            if(countL== countR){
                ans++;
                countL=0;
                countR=0;
            }
        }

        return ans;
    }
};