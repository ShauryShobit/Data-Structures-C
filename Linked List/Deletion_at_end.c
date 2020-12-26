//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include <stdio.h>
#include <stdlib.h>
struct xyz{
    int data;
    struct xyz *next;
};
int display(struct xyz* p){
    while(p != NULL){
        printf("%d\n", p -> data);
        p = p -> next;
    }
    return 0;
}

void delete_end(struct xyz* head){
    struct xyz *p1,*p2;
    if(head == NULL){
        printf("\nlist is empty");
    }
    else if(head -> next == NULL){
            head = NULL;
            free(head);
    }
    else{
        p1 = head;
        while(p1 -> next != NULL){
            p2 = p1;
            p1 = p1 -> next;
        }
        p2 -> next = NULL;
        free(p1);
        }
        p1 = NULL;
}
int main(){
    struct xyz *a = NULL;
    struct xyz *b = NULL;
    struct xyz *c = NULL;
    struct xyz *d = NULL;
    struct xyz *e = NULL;

    a = (struct xyz*)(malloc(sizeof(struct xyz*)));
    b = (struct xyz*)(malloc(sizeof(struct xyz*)));
    c = (struct xyz*)(malloc(sizeof(struct xyz*)));
    d = (struct xyz*)(malloc(sizeof(struct xyz*)));
    e = (struct xyz*)(malloc(sizeof(struct xyz*)));

    a -> data = 2;
    a -> next = b;

    b -> data = 4;
    b -> next = c;

    c -> data = 6;
    c -> next = d;

    d -> data = 8;
    d -> next = e;

    e -> data = 10;
    e -> next = NULL;

    printf("Old Linked List: \n");
    display(a);

    delete_end(a);

    printf("Hello this is @Mr.Tech_In output\nNew Linked List: \n");
    display(a);

    return 0;
}
