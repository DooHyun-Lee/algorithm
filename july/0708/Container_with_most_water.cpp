// increment left_idx if it has smaller height cause can't afford max area anymore
// decrement right_idx if it has smaller height for the same reason
// if equal, decrement anything

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left_idx = 0;   int right_idx = height.size()-1;
        while(left_idx < right_idx){
            area = max(area,min(height[left_idx],height[right_idx])*(right_idx-left_idx));
            if(height[left_idx]>height[right_idx])
                right_idx--;
            else
                left_idx++;
        }
        return area;
    }
};
