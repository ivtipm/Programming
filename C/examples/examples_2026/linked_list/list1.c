
/// Тип данных описывающий узел односвязного списка
#include <stdlib.h>
struct Node{
    int data;               // данные узла списка
    struct Node * next;     // указатель на след. узел списка
};

int main(){

    // выделение памяти под узел списка
    // head -- указатель на первый узел списка
    struct Node * head = malloc( sizeof(struct Node) );
    head->data = 10;
    head->next = NULL;
    // указатель на хвостовой узел
    struct Node * tail = head;

    // создание нового узла списка
    struct Node* cur = malloc( sizeof(struct Node) );
    cur->data = 20;
    cur->next = NULL;
    // присоединим новый узел к первому узлу
    head->next = cur;
    tail = cur;         // обновляем хвостовой узел

    // создание нового узла списка
    cur = malloc( sizeof(struct Node) );
    cur->data = 30;
    cur->next = NULL;

    // присоединим новый узел cur ко второму узлу списка ( добавим узел в конец списка )
    (head->next) -> next = cur;
    // (head->next) -- обращение ко второму узлу
    // struct Node* node2 = head->next;
    // node2 -> next = cur;
    tail = cur;         // обновляем хвостовой узел

    // создание нового узла списка
    cur = malloc( sizeof(struct Node) );
    cur->data = 40;
    cur->next = NULL;

    // присоединим новый узел cur к третьему узлу списка ( добавим узел в конец списка )
    // ((head->next) -> next) -> next = cur;
    // head -> next -> next -> next = cur;
    tail->next = cur;   // добавляем элемент после хвоста списка
    tail = cur;         // обновляем хвостовой узел


}
