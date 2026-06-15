// class Solution {
// public:
//     int myAtoi(string s) {
//         int n = s.size();
//         int i=0;

//         while(i<n && s[i]==' '){
//             i++;
//         }

//         int sign = 1;
//         if(i<n && (s[i]=='+' || s[i]=='-')){
//             if(s[i] == '-'){
//                 sign = -1;
//             }
//             i++;
//         }

//         long long num=0;

//         while(i<n && isdigit(s[i])){
//             int digit = s[i]-'0';

//             num = num*10 + digit;

//             if(sign * num > INT_MAX){
//                 return INT_MAX;
//             }

//             if(sign*num < INT_MIN){
//                 return INT_MIN;
//             }
//             i++;
//         }    
//         return sign*num;
//     }
// };


class Solution {
public:
    long long solve(string &s, int i, long long num, int sign) {
        if (i >= s.size() || !isdigit(s[i]))
            return sign * num;

        int digit = s[i] - '0';
        num = num * 10 + digit;
        if (sign * num > INT_MAX)
            return INT_MAX;

        if (sign * num < INT_MIN)
            return INT_MIN;
        return solve(s, i + 1, num, sign);
    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ')
            i++;

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        return (int)solve(s, i, 0, sign);
    }
};