class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        int start = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                count++;
            }
            else{
                count--;
            }
            //decomposition mil gya
            if(count == 0){
                for(int j=start+1; j<i; j++){
                    ans += s[j];
                }
                start = i+1;
            }
        }
        return ans;
    }
};