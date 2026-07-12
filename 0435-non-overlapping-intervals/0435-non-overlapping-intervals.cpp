class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(), intervals.end());
        int lastIdx = intervals[0][1];

        for(int i=1; i<n; i++){
            if(lastIdx > intervals[i][0]){
                count ++;
                lastIdx = min(lastIdx, intervals[i][1]);
            }
            else{
                lastIdx = intervals[i][1];
            }
        }
        return count;
    }
};