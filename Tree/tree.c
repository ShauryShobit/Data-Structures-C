//This Program is copyrighted by Mr.Tech_In 
// Hi this is your one and only Shaury Shobit
#include <stdio.h> 
#include <stdlib.h> 
struct node { 
 int item; 
 struct node* left; 
 struct node* right; 
}; 
void order(struct node* root) {
 if (root == NULL) return; 
 order(root->left); 
 printf("%d ->", root->item); 
 order(root->right); 
} 
// Create a new Node 
struct node* createNode(int value) { 
 struct node* newNode = malloc(sizeof(struct node));  newNode->item = value; 
 newNode->left = NULL; 
 newNode->right = NULL; 
 return newNode; 
} 
// Insert on the left of the node 
struct node* insertLeft(struct node* root, int value) {  root->left = createNode(value); 
 return root->left; 
} 
// Insert on the right of the node 
struct node* insertRight(struct node* root, int value) {  root->right = createNode(value); 
 return root->right; 
} 
int main() { 
 struct node* root = createNode(1); 
 insertLeft(root, 2);
 insertRight(root, 3); 
 insertLeft(root->left, 4); 
 insertLeft(root->right, 5); 
 printf("\nHi this output is of Mr.Tech - \n");  printf("Nodes are as follows \n"); 
 order(root); 
  
 } 
