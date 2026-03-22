//This is optimal approach (2-pointer)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int left=0;
        int right= n-1;

        while(left<right){
            int sum = numbers[left]+numbers[right];
            
            if(sum==target){
                return {left+1 , right+1};
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
};        

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n = numbers.size();

//         unordered_map<int,int> mp;
//         for(int i=0;i<n;i++){
//             int need = target-numbers[i];

//             if(mp.find(need) != mp.end()){
//                 return {mp[need]+1,i+1};
//             }
//             mp[numbers[i]] = i;
//         }
//         return {};
//     }
// };
// This is not optimal.