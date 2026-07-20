class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Current container area
            int width = right - left;
            int currArea = min(height[left], height[right]) * width;

            // Update answer
            maxArea = max(maxArea, currArea);

            // Move the smaller height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};