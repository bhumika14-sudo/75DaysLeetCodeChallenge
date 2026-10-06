class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        string ans = "";

        int i = n-1, j=m-1, carry =0;

        while(i>=0 || j>=0){
            int x=0, y=0;
            if(i>=0){
                x = a[i]-'0';
            }
            if(j>=0){    
                y = b[j]-'0';
            }
            
            // 0 + 0
            if(x==0 && y==0){
                if(carry == 1){
                    ans+= '1';
                    carry = 0;
                }
                else{
                    ans += '0';
                }
            }

            // 1 + 0
            else if(x == 1 && y == 0){
                if(carry == 1){
                    ans += '0';
                    carry = 1;
                }
                else{
                    ans += '1';
                    carry = 0;
                }
            }

            // 0 + 1
            else if(x == 0 && y == 1){
                if(carry == 1){
                    ans += '0';
                    carry = 1;
                }
                else{
                    ans += '1';
                    carry = 0;
                }
            }

            // 1 + 1
            else{
                if(carry == 1){
                    ans += '1';
                }
                else{
                    ans += '0';
                }

                carry = 1;
            }
            i--;
            j--;
        }

        if(carry == 1){
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};