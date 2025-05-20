//---- Libraries ----//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---- Defines ----//
#define MALLOC_FAILURE 1
#define SUCCESS 0

//---- Node struct ----//
struct Node {
  int id;
  struct Node* next;
};

//---- Functions ----//
void mallocCheck(struct Node* node){ //Checks if malloc returns NULL, closes down program if so
  if(node == NULL){
    printf("Failure during malloc, shutting down.");
    exit(MALLOC_FAILURE);
  }
}

void createNode(struct Node* node, int enteredId, struct Node* nextNode){ //Creates each node in list
  node -> id = enteredId;
  node -> next = nextNode;
}

void printList(struct Node* head){//Loops through every item in the list and prints until it reaches NULL 
  struct Node* current = head;
  
  while(current != NULL){
    printf("%d -> ", current -> id);
    current = current -> next;
  }
  printf("NULL\n");
}

void freeList(struct Node* head){//Loops through each item in the linked list and frees until it reaches NULL
  struct Node* nextNode;
  struct Node* current = head;

  while(current != NULL){
    nextNode = current -> next;
    free(current);
    current = nextNode;
  }
}


//---- Main ----//
int main () {  
  //---- Creating list items ----//
  struct Node* head = malloc(sizeof(struct Node));
  struct Node* second = malloc(sizeof(struct Node));
  struct Node* third = malloc(sizeof(struct Node));
  struct Node* fourth = malloc(sizeof(struct Node));

  //---- Check for malloc failure ----//
  mallocCheck(head);
  mallocCheck(second);
  mallocCheck(third);
  mallocCheck(fourth);

  //---- Adding to list items ----//
  createNode(head, 1, second);
  createNode(second, 2, third);
  createNode(third, 3, fourth);
  createNode(fourth, 4, NULL);

  //---- Print list ----//
  printList(head);
  
  //---- Free list ----//
  freeList(head);
  return SUCCESS;
}
