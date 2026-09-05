class StockSpanner {
public:
    // ---------------------------------------------------------------------
    // DATA STRUCTURE CHOICE: a stack of (price, span) pairs.
    //
    // Why a stack and not just an array of every past price?
    // Because once a past day's price is proven to be <= today's price,
    // that day becomes irrelevant to look at individually ever again: any
    // future price that beats today's price will automatically beat that
    // older day's price too. So instead of remembering every single day,
    // we "merge" a run of consecutive covered days into one summary entry:
    // (that day's price, how many consecutive days ending on that day were
    // already known to be <= that price).
    //
    // The stack holds these summary entries with prices that strictly
    // decrease from bottom to top - that's what makes it a "monotonic
    // decreasing" stack, and it's the key invariant the whole algorithm
    // relies on.
    // ---------------------------------------------------------------------
    stack<pair<int, int>> st;   // st.top() = {price, span} of the most recent active entry

    StockSpanner() {
        // Nothing to initialize besides the empty stack.
        // It's empty because no prices have arrived yet.
    }

    int next(int price) {
        // Every day starts with a baseline span of 1: a day always counts
        // itself, even in the worst case where every earlier day was
        // more expensive.
        int span = 1;

        // Look at the top of the stack (the most recently recorded entry).
        // If that entry's price is <= today's price, today is high enough
        // to "cover" that entry's entire span. Because the stack is kept
        // monotonic decreasing, covering that entry also means covering
        // every earlier day that was already folded into it - we don't
        // need to check them one by one.
        //
        // So we keep popping and accumulating spans until either:
        //   (a) the stack becomes empty  -> today is a new high so far, or
        //   (b) we hit an entry whose price is strictly greater than
        //       today's price -> that acts as a "wall" we cannot see past,
        //       so we stop there.
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;   // absorb that entry's span into today's count
            st.pop();                  // it no longer needs to be tracked on its own
        }

        // Push today's own summary entry: its price, and the total span
        // just computed (today itself + everything it absorbed).
        // This is what future next() calls will compare against.
        st.push({price, span});

        // Return today's span as the answer for this call.
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// ---------------------------------------------------------------------
// WHY THIS IS EFFICIENT (amortized analysis)
//
// Time: over the entire lifetime of the object, each price is pushed
// onto the stack exactly once, and can therefore be popped at most once.
// So across n total calls to next(), the sum of all pop operations done
// by ALL calls combined is at most n. That means the total work across
// every call together is O(n), giving an AMORTIZED O(1) time per call,
// even though a single call (e.g. today is a new all-time high) can pop
// many entries at once and briefly look like O(n) on its own.
//
// Space: O(n) in the worst case - if prices are strictly increasing every
// day (e.g. 1, 2, 3, 4, 5, ...), nothing is ever popped, so the stack
// keeps growing by exactly one entry per call.
// ---------------------------------------------------------------------