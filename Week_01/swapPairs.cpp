class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = head;
        while (tmp && tmp->next) {
            swap(tmp->val, tmp->next->val);
            tmp = tmp->next->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* res = pre;
        while (pre->next && pre->next->next) {
            ListNode* fir = pre->next, *snd = pre->next->next;

            fir->next = snd->next;
            snd->next = fir;
            pre->next = snd;
            pre = fir;
        } 
        return res->next;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // We use a dummy head node to make handling head operations simpler
        ListNode *dummy = new ListNode(-1), *tail = dummy;
        // add the dummy node to list
        tail->next = head;
        
        while(head && head->next) {
            ListNode *nextptr = head->next->next;
            
            tail->next = head->next;  
            head->next->next = head;
            head->next = nextptr;

            tail = head;
            head = head->next;

        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};