#include "LinkedList.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL) return NULL;
        while(head->val==val){
            head=head->next;
            if (head==NULL) return NULL;
        }

        ListNode * first = head;
        ListNode * second = head->next;

        while(second!=NULL) {
            if(second->val == val){
                first->next = second->next;
                second = second->next;
            }
            else {
                first = second;
                second = second->next;
            }
        }
        return head;
    }
};

int main() {
    vector<int> list = {1, 2, 2, 4};
    ListNode* head = vectorToListNode(list);
    prettyPrintLinkedList(head);
    head = Solution().removeElements(head, 2);
    prettyPrintLinkedList(head);
    return 0;
}
