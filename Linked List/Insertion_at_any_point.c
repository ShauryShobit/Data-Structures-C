//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include <stdio.h> 
#include <stdlib.h> 
struct node{ 
    int data; 
    struct node *next; 
};  
int display(struct node* p){ 
    while(p != NULL){ 
    printf("%d\n", p -> data); 
       p = p -> next; 
    } 
    return 0; 
} 
 void add(struct node* head, int data, int pos){ 
    struct node *ptr = head; 
    struct node *ptr2 = malloc(sizeof(struct node)); 

    ptr2 -> data = data; 

    ptr2 -> next = NULL; 
 
    pos--; 

    while(pos != 1){ 
        ptr = ptr-> next;
        pos--; 
    } 
    ptr2 -> next = ptr -> next; 

    ptr -> next = ptr2; 
} 
 int main(){ 
    struct node *a = NULL; 
    struct node *b = NULL; 
    struct node *c = NULL; 

    a = (struct node*)(malloc(sizeof(struct node*))); 
    b = (struct node*)(malloc(sizeof(struct node*))); 
    c = (struct node*)(malloc(sizeof(struct node*))); 

    a -> data = 10; 
    a -> next = b; 

    b -> data = 30; 
    b -> next = c; 

    c -> data = 40; 
    c -> next = NULL; 

     printf("Linked List before insertion: \n"); 
    display(a); 

    int data,placement; 
    printf("\nHello this is @Mr.Tech_In output \nEnter Data: "); 
    scanf("%d",&data); 
    printf("\nEnter Position(Keep it less than 5): "); 
    scanf("%d",&placement); 
    printf("\n"); 
    add(a, data, placement); 
    struct node *ptr = a; 
   printf("Linked List after insertion: \n"); 
    display(a); 
    return 0; 
} 
