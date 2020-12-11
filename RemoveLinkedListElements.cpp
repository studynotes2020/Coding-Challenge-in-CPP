#include "LinkedList.h"

class Solution {
    public:
      ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
            
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
            
        ListNode* prev = newHead;
            
        while(head!=NULL){
          if(head->val!=val){
            prev=head;
            head=head->next;
          }
          else{
            ListNode* t = head;
            prev->next = head->next;
            head = head->next;
            delete t;
          }
        }
        ListNode* t = newHead->next;
        delete newHead;
        return t; //return pointer to beginning

      }
};

int main() {
    vector<int> list = {1, 3, 3, 4};
    ListNode* head = vectorToListNode(list);
    prettyPrintLinkedList(head);
    head = Solution().removeElements(head, 2);
    prettyPrintLinkedList(head);
    return 0;
}

