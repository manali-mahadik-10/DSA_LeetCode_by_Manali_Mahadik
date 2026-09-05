class StockSpanner {
public:
    // Our stack holds pairs: (price, span)
    // "span" here just means: how many days (including that day)
    // are already bundled up under this price.
    stack<pair<int, int>> st;

    StockSpanner() {
        // Nothing to set up. The stack starts empty because
        // no prices have been given yet.
    }

    int next(int price) {
        // Today counts as at least 1 day (itself), no matter what.
        int span = 1;

        // Keep checking the top of the stack.
        // If the price sitting on top is <= today's price,
        // that means today is expensive enough to "swallow" it.
        // So we remove it (pop) and add its count into our own count.
        while (!st.empty() && st.top().first <= price) {
            span = span + st.top().second;
            st.pop();
        }

        // Now put today's own price and total count onto the stack,
        // so future days can compare against it.
        st.push({price, span});

        // Give back today's answer.
        return span;
    }
};