class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pos=0;
        int neg=1;

        for(int x:nums){
            if(x>0){
                ans[pos]=x;
                pos+=2;
            }
            else{
                ans[neg]=x;
                neg+=2;
            }
        }
        return ans;
    }        
};

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int> pos,neg;

//         for(int x:nums){
//             if(x>0) pos.push_back(x);
//             else neg.push_back(x);
//         }
        
//         vector<int> ans(n);
//         int po=0;
//         int ne=0;

//         for(int i=0;i<n;i++){
//             if(i%2==0){
//                 ans[i] = pos[po];
//                 po++;
//             }
//             else{
//                 ans[i]=neg[ne];
//                 ne++;
//             }
//         }
//         return ans;
//     }
// };