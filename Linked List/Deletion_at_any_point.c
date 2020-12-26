//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include <stdio.h> 
#include <stdlib.h> 
struct xyz{ 
    int data; 
    struct xyz *agla; 
}; 

int display(struct xyz* p){ 
    while(p != NULL){ 
        printf("%d\n", p -> data); 
        p = p -> agla; 
    } 
    return 0; 
} 



void delete_key(struct xyz** head, int key){ 
    struct xyz* temp = *head, *prev; 
    if (temp != NULL && temp -> data == key){ 
        *head = temp -> agla; 
        free(temp); 
        return; 
    } 

    while (temp != NULL && temp -> data != key) 
    { 
        prev = temp; 
        temp = temp->agla; 
    } 
 
    if (temp == NULL){ 
        return; 
    } 
    prev -> agla = temp -> agla; 
    free(temp); 
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
 
    a -> data = 3; 
    a -> agla = b; 

    b -> data = 6; 
    b -> agla = c; 

    c -> data = 9; 
    c -> agla = d; 

    d -> data = 12;  
    d -> agla = e;  

    e -> data = 15;  
    e -> agla = NULL;  

    printf("Old Linked List: \n"); 
    display(a); 
    int key; 
    printf("Hello this is @Mr.Tech_In output\nEnter data from above list to delete: "); 
    scanf("%d", &key); 
    delete_key(&a, key); 
    printf("\nNew Linked List: \n"); 
    display(a); 
    return 0; 
} 
