class Solution {
public:
    int solve(vector<int>& weights, int capacity){
        int n = weights.size();
        int days=1;
        int load = 0;

        for(int i=0; i<n; i++){
            if(load + weights[i] <= capacity){
                load += weights[i];
            }
            else{
                days++;
                load = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(solve(weights, mid) <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};