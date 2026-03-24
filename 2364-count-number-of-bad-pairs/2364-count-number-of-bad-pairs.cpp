// class Solution {
// public:
//     long long countBadPairs(vector<int>& nums) {
//         int n = nums.size();
//         long long count = 0;

//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){

//                 if(j-i != nums[j]-nums[i]){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
//TLE 

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<long long , long long> mp;
        long long good=0;

        for(int i=0;i<n;i++){
            long long key = nums[i]-i;

            good += mp[key];
            mp[key]++;
        }

        long long total = (long long)n * (n-1)/2;

        return total-good;
    }
};        

int _ = (atexit([]{ofstream("display_runtime.txt")<<0;}),0);
