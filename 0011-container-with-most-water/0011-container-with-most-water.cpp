class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea1=0;
        int n=height.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int currArea=min(height[left],height[right])*(right-left);
            maxArea1=max(currArea, maxArea1);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea1;

    }
};