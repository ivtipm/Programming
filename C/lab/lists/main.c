#include <stdlib.h>
#include <stdio.h>

/// Узел односвязного списка
struct Node{
    int data;
    struct Node *next;
};
 

struct Node* make_node(int value){
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct Node* push_front(struct Node* head, struct Node* new_node){
    if (head == NULL) {
        return new_node;
    }
    else{
        new_node->next = head;
        return new_node; 
    }

}

void print_list(struct Node* head){
    struct Node* cur = head;

    while ( cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

void free_list(struct Node* head){
    while( head ){
        struct Node* tmp = head;
        free(tmp);
        head = head->next;
    }
}

int main(){
    // В С переменные для структур всегда объвляются со словом struct
    struct Node * head = NULL;
    // но можно этого избежать если объявлять структуру через typedef

    head = push_front(NULL, make_node(10));
    head = push_front(head, make_node(20));
    head = push_front(head, make_node(30));

    print_list(head);

    free(head);
    puts("");

}