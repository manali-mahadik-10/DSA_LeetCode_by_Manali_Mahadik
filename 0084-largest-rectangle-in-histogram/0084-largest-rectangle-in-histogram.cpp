class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); // how many bars/kids we have

        // leftSmaller[i]  = index of the closest bar to the LEFT of bar i
        //                   that is SHORTER than bar i
        // rightSmaller[i] = index of the closest bar to the RIGHT of bar i
        //                   that is SHORTER than bar i
        // If no such bar exists, we use -1 for left (imaginary wall before
        // the array) or n for right (imaginary wall after the array).
        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);

        // The stack = our "waiting line" of bars that haven't yet found
        // a shorter bar near them.
        stack<int> st;

        // ---------- WALK 1: left to right ----------
        // Goal: fill in leftSmaller[i] for every bar.
        for (int i = 0; i < n; i++) {

            // If the bar waiting at the front of the line (top of stack)
            // is the same height or taller than our current bar, it can
            // never be used as "the shorter neighbor" for anything from
            // here onward, so remove it from the waiting line.
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // Whoever is left in the waiting line now (if anyone) is
            // exactly the closest shorter bar to our left.
            if (st.empty()) {
                leftSmaller[i] = -1;   // nobody shorter exists to the left
            } else {
                leftSmaller[i] = st.top();
            }

            // Add our current bar to the waiting line for future bars to check.
            st.push(i);
        }

        // Empty the waiting line completely so we can reuse it for the next walk.
        while (!st.empty()) {
            st.pop();
        }

        // ---------- WALK 2: right to left ----------
        // Exact same idea as Walk 1, just walking backward, so we
        // find the closest shorter bar to the RIGHT instead.
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                rightSmaller[i] = n;  // nobody shorter exists to the right
            } else {
                rightSmaller[i] = st.top();
            }

            st.push(i);
        }

        // ---------- FINAL STEP: work out the area for every bar ----------
        // If bar i is the SHORTEST bar in its rectangle, that rectangle
        // stretches from just after leftSmaller[i] to just before
        // rightSmaller[i].
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = rightSmaller[i] - leftSmaller[i] - 1; // how many bars fit
            int area = heights[i] * width;                    // height times width
            maxArea = max(maxArea, area);                     // remember the biggest one
        }

        return maxArea;
    }
};