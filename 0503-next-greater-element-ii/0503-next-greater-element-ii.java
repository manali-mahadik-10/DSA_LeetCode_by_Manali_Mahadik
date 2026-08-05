class Solution {

    public int[] nextGreaterElements(int[] arr) {

        int n = arr.length;

        int[] ans = new int[n];

        Stack<Integer> st = new Stack<>();

        // preload stack
        for (int i = n - 2; i >= 0; i--) {
            st.push(arr[i]);
        }

        // normal next greater logic
        for (int i = n - 1; i >= 0; i--) {

            while (!st.isEmpty() && st.peek() <= arr[i]) {
                st.pop();
            }

            if (st.isEmpty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.peek();
            }

            st.push(arr[i]);
        }

        return ans;
    }
}