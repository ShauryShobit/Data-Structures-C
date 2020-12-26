//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include<stdio.h>
int main()
{
    int arr[10];
    int i,k;
    printf("how many number you want to store: ");
    scanf("%d", &k);
    printf("\nEnter Elements: \n");
    for(int i = 0; i < k; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < k; i++){
        printf("%d", arr[i]);
        printf("\n");
    }
    return 0;
}