class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        for (auto l : lists) {
            if (l) pq.push(l);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;

            if (tail->next) {
                pq.push(tail->next);
            }
        }

        return dummy.next;
    }
};