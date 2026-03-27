class Solution {
public:
    int lengthOfLongestSubstring(string st) {

        unordered_set<char> set;
        int right=0 , left=0;
        int maxLen = 0;

        while(right < st.size()){
            if(set.find(st[right])== set.end()){
                set.insert(st[right]);
                maxLen = max(maxLen , right-left+1);
                right++;
            }
            else{
                set.erase(st[left]);
                left++;
            }
        }
        return maxLen;
    }
};