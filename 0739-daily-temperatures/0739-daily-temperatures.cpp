class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};


// This is my 1st approach Brute-force

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> answer(n,0);
        
//         for(int start=0; start<n; start++){
//             for(int end = start+1 ; end<n ; end++){
//                 if(temperatures[start] < temperatures[end]){
//                     answer[start] = end - start;
//                     break;
//                 }
//             }
//         }
//         return answer;
//     }
// };