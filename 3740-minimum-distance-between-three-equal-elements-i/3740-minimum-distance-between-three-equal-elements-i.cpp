class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int , vector<int>> mp;
        int n = nums.size();
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for (auto &it : mp) {
            auto &indices = it.second;

            if (indices.size() < 3) continue;

            // Try consecutive triplets
            for (int i = 0; i + 2 < indices.size(); i++) {
                int dist = 2 * (indices[i + 2] - indices[i]);
                ans = min(ans, dist);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
   





// class Solution {
// public:
//     int minimumDistance(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> mp;
//         vector<int> vec;

//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }
//         for(int i=0;i<n;i++){
//             if(mp[nums[i]] == 3){
//                 vec.push_back(i);
//             }
//         }
//         if(vec.size()<3) return -1;

//         int ans = abs(vec[0]-vec[1]) + abs(vec[1]-vec[2]) + abs(vec[2]-vec[0]);
//         return ans;
//     }
// };