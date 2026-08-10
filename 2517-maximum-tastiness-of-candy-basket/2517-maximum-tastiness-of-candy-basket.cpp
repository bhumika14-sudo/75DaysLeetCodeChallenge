class Solution {
public:
    bool solve(vector<int>& price, int k , int canday){
        int n = price.size();
        int count = 1;
        int last = price[0];

        for(int i=1; i<n; i++){
            if(price[i] - last >= canday){
                count++;
                last = price[i];
            }
        }
        return count >= k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int low = 1;
        int high = price[n-1] - price[0]; 
        int ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(solve(price, k, mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};