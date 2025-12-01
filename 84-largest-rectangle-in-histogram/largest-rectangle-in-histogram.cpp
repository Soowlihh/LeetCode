class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);
        stack<int> stacks;

        for(int i = 0; i < n; i++){
            while(!stacks.empty() && heights[stacks.top()] >= heights[i]){
                stacks.pop();
            }
            if(!stacks.empty()){
                leftMost[i] = stacks.top();
            }
            stacks.push(i);
        }

        while(!stacks.empty()) stacks.pop();
        
        for(int i = n - 1; i >= 0; i--){
            while(!stacks.empty() && heights[stacks.top()] >= heights[i]){
                stacks.pop();
            }
            if(!stacks.empty()){
                rightMost[i] = stacks.top();
            }
            stacks.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            leftMost[i] += 1;
            rightMost[i] -= 1;
            maxArea = max(maxArea, heights[i] * (rightMost[i] - leftMost[i] + 1));
        }
return maxArea;
    }
};