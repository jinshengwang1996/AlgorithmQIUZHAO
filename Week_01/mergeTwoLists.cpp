class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr) return l1 == nullptr ? l2 : l1;
        ListNode* ptr = l1;
        vector<int> nums;

        while (ptr->next) {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
        ptr->next = l2;
        while (ptr) {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
        sort(nums.begin(), nums.end(), std::greater<int>());
        ptr = l1;
        while (ptr) {
            ptr->val = nums.back();
            nums.pop_back();
            ptr = ptr->next;
        }
        return l1;
    } 
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prev = new ListNode(-1);
        ListNode* res = prev;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                res->next = l1;
                l1 = l1->next;
            }
            else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        res->next = l1 == NULL ? l2 : l1;

        // delete the dummy head
        ListNode *head = prev->next;
        delete prev;
        return head;
    } 
};
