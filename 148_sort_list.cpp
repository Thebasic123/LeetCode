//recursively 
class Solution {
public:
    ListNode* mergeList(ListNode* list1,ListNode* list2){
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<=list2->val){
            list1->next = mergeList(list1->next,list2);
            return list1;
        }else{
            list2->next = mergeList(list1,list2->next);
            return list2;
        }
        
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode *pre = head;
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p2!=NULL&&p2->next!=NULL){
            pre = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        pre->next = NULL;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(p1);
        return mergeList(h1,h2);
        
    }
};
//iteratively 
