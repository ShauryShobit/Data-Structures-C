//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include<stdio.h>
#include<stdlib.h>
int n=10, top = -1, *storage;
void push(int x){
    if(top==n) return;
    storage[++top]=x;
}
int pop(){
    if(top==-1) return -1;
    return storage[top--];
}
void display(){
    printf("[");
    for(int i=top ; i>-1 ; i--) printf(" %d  ",storage[i]);
    printf("]");
    printf("\n\n");    
}
int main(){
    storage = (int*)malloc(n*sizeof(int));
    push(7);
    push(14);
    push(21);
    push(28);
    push(35);
    printf("These are the elements of stack -\n");    
    display();
        printf("The element at the top i.e-[ %d",pop());
    printf(" ]");    
    printf("\nHi this output is of Mr.Tech -\n\n");        
    printf("Displaying elements of the stack after pop implementation-\n");    
    display();    
    return 0;
}
