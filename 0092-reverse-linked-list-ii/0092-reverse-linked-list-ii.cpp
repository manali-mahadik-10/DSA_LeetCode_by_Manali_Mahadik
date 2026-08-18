class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;

        for(int i = 1; i < left; i++){
            before = before->next;
        }
        //before now before the left element...

        ListNode* curr = before->next;
        ListNode* tail = curr;
        ListNode* prev = nullptr;

        int len = right - left + 1;

        while(len--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        before->next = prev;
        tail->next = curr;

        return dummy->next;
    }
};