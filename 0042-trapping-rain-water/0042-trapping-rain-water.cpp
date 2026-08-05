class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int i=0 , j=n-1;
        int water = 0;

        while(i < j){
            if(height[i] <= height[j]){
                if(leftMax < height[i]){
                    leftMax = height[i];
                }
                else{
                    water = leftMax - height[i];
                }
                i++;
            }
            else{
                if(rightMax < height[j]){
                    rightMax = height[j];
                }
                else{
                    water = rightMax - height[j];
                }
                j--;
            }
        }
        return water;
    }
};