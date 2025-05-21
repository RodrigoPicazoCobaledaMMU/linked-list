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
    printf("Freed node at id: %d\n", current -> id);
    free(current);
    current = nextNode;
  }
}

int countNode(struct Node* head){
  struct Node* nextNode;
  struct Node* current = head;
  int nodeCount = 0;

  while(current != NULL){
    nextNode = current -> next;
    nodeCount++;
    current = nextNode;
  }
  printf("Finished counting, the total amount of nodes is %d\n", nodeCount);
  return nodeCount;
}

void insertEnd(struct Node* head){
  // Needs work !
  struct Node* current = head;
  
  char userId[5];
  printf("Enter the id you want the new node to be: ");
  fgets(userId, sizeof(userId), stdin);
  printf("You entered %s", userId);
  int validatedUserId = atoi(userId);

  struct Node* newNode = malloc(sizeof(struct Node));
  mallocCheck(newNode);
  createNode(newNode,validatedUserId,NULL);
  
  while(current != NULL){
    if(current -> next == NULL){
      current -> next = newNode;
      printf("Added a new node !\n");
      break;
    } else {
      current = current -> next;
    }
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
  countNode(head); 

  insertEnd(head);
  printList(head);
  countNode(head); 
  //---- Free list ----//
  freeList(head);
  return SUCCESS;
}
