//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include <stdio.h>
#include <stdlib.h>
struct xyz{
    int data;
    struct xyz *agla;
};
int show(struct xyz* p){
    while(p != NULL){
        printf("%d\t", p -> data);
        printf("%p\n", p -> agla);
        p = p -> agla;
    }
    return 0;
}
int main(){
    struct xyz *a = NULL;
    struct xyz *b = NULL;
    struct xyz *c = NULL;
    struct xyz *d = NULL;

    a = (struct xyz*)(malloc(sizeof(struct xyz*)));
    b = (struct xyz*)(malloc(sizeof(struct xyz*)));
    c = (struct xyz*)(malloc(sizeof(struct xyz*)));
    d = (struct xyz*)(malloc(sizeof(struct xyz*)));

    a -> data = 5;
    a -> agla = b;

    b -> data = 10;
    b -> agla = c;

    c -> data = 15;
    c -> agla = d;

    d -> data = 20;
    d -> agla = NULL;

    printf("Hello this is @Mr.Tech_In output\n");
    show(a);
    return 0;
}
