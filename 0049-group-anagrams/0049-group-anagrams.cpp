class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string , vector<string>> mp;
        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
}; 

// This is the optimal approach

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {

//         int n=strs.size();
//         vector<vector<string>> ans;
//         vector<bool> visited(n,false);

//         for(int i=0;i<n;i++){
//             if(visited[i]) continue;

//             vector<string> group;
//             group.push_back(strs[i]);
//             visited[i]=true;

//             vector<int> freq1(26,0);

//             for(char c:strs[i]){
//                 freq1[c-'a']++;
//             }

//             for(int j=i+1;j<n;j++){
//                 vector<int> freq2(26,0);

//                 for(char c:strs[j]){
//                     freq2[c-'a']++;
//                 }

//                 if(freq1 == freq2){
//                     group.push_back(strs[j]);
//                     visited[j]=true;
//                 }
//             }
//             ans.push_back(group);
//         }
//         return ans;
//     }
// };

// This is my first approach . This approach is a bit time taking to TLE arrived.


