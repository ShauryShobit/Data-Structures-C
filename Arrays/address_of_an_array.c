//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include<stdio.h>

int main( )
{
        int arr[100];
        int i,n;
        printf("Enter number of elements you want to store:");
        scanf("%d", &n);
        printf("\nEnter elements of the array : \n");
        for(i=0; i<n; i++)
        {
                scanf("%d", &arr[i]);
        }
        printf("\nArray elements with their addresses:\n");
        for(i=0; i<n; i++)
        {
            printf("Address of arr[%d] = %p\n", i, &arr[i] );
        }
        return 0;
}