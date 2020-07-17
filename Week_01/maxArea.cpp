class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxares = 0;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            int h = min(height[l], height[r]);
            maxares = max(maxares, (r - l) * h);
            while (l < r && height[l] <= h) ++l;
            while (l < r && height[r] <= h) --r;
        }
        return maxares;
    }
};