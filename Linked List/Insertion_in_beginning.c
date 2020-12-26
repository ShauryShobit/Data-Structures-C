//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node *join(struct node *start, int x){
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = x;
    ptr -> link = NULL;
    ptr -> link = start;
    start = ptr;
    return start;
}
void display(struct node* start){
    if(start == NULL){
        printf("List is empty");
    }
    struct node* ptr = NULL;
    ptr = start;
    while(ptr != NULL){
        printf("%d\n",ptr -> data);
        ptr = ptr -> link;
    }
}
int main(){
    struct node *start = NULL;
    start = (struct node*)(malloc(sizeof(struct node*)));

    start -> data = 30;
    start -> link = NULL;

    struct node *current = (struct node*)(malloc(sizeof(struct node*)));

    current -> data = 45;
    current -> link = NULL;
    start -> link = current;

    struct node *now = (struct node*)(malloc(sizeof(struct node*)));

    now -> data = 60;
    now -> link = NULL;
    current -> link = now;

    display(start);

    int data;

    printf("\nEnter the new node: ");
    scanf("%d",&data);
    printf("\nHello this is @Mr.Tech_In output \n");

    start = join(start, data);
    current = start;
    display(start);

    return 0;
}
