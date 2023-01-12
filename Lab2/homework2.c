#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;

ListNode* removeElements(ListNode* head, int val) {
    while(head && head->val == val)
        head = head->next;
    if(head) {
        ListNode *p = head, *q = head->next;
        while(q) {
            if(q->val == val)
                p->next = q->next;
            else
                p = p->next;
            q = q->next;
        }
    }
    return head;
}

int main(){
    struct ListNode *head = NULL, *cur = head;
    int array[7] = {1, 2, 6, 3, 4, 5, 6};
    int len = 7;
    for (int i = 0; i < len; i++) {
        ListNode *node = (ListNode*) malloc(sizeof(ListNode));
        node->val = array[i];
        node->next = NULL;
        if (!head){
            head = node;
            cur = node;
        }else {
            cur->next = node;
            cur = cur->next;
       }
    }

    head = removeElements(head,6);
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
