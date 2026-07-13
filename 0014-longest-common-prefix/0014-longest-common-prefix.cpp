class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string temp = strs[0];

        for(int i=1; i<n; i++){
            while(strs[i].find(temp) != 0){
                temp.pop_back();
            }
        }
        return temp;
    }
};