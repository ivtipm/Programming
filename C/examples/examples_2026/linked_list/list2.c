
/// Тип данных описывающий узел односвязного списка
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;               // данные узла списка
    struct Node * next;     // указатель на след. узел списка
};


/// Создаёт новый узел связного списка с данными data
struct Node* create_node(int data){
    struct Node * node = malloc( sizeof(struct Node) );
    node->data = data;
    node->next = NULL;
    return node;
}


/// выводит список на экран в одну строку
void print_list(struct Node* head){
    struct Node* c = head;
    while ( c != NULL)      // проверка: стоим на не пустом указателе?
    {
        printf("%d ", c->data);
        c = c->next;            // переходим на след. узел
    }
}

/// Добавляет новый узел с данными data в хвост списка
/// Возвращает адрес нового конца списка
struct Node*  add_new_last_node(struct Node* tail, int data){
     struct Node * new_node = create_node( data );
     tail -> next = new_node;
     return new_node;
}

int main(){

    // выделение памяти под узел списка
    // head -- указатель на первый узел списка
    struct Node * head = create_node(10);
    struct Node * tail = head;              // указатель на хвостовой узел

    // создание нового узла списка
    tail = add_new_last_node(tail, 20);       // добавляем узел в конец. обновляем хвостовой узел
    tail = add_new_last_node(tail, 30);
    tail = add_new_last_node(tail, 40);

    print_list(head);

    puts("");

}
