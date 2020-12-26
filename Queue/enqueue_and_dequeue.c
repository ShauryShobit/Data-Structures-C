//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include <stdio.h>
#define SIZE 7
void enqueue(int);
void dequeue();
void display();
int items[SIZE], front = -1, rear = -1;
void enqueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted value is -> %d", value);
  }
}
void dequeue() {
  if (front == -1)
    printf("Queue is Empty!!");
  else {
    printf("\nFront will be Deleted i.e. %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}
void display() {
    printf("\n\nHi this output is of Mr.Tech -");
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}
int main() {
  dequeue();
  enqueue(13);
  enqueue(26);
  enqueue(39);
  enqueue(52);
  enqueue(65);
  enqueue(78);
  enqueue(91);
  enqueue(104);
  display();
  dequeue();

  display();
  return 0;
}

