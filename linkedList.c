//---- Libraries ----//
#include <stdio.h>
#include <stdlib.h>

//---- Defines ----//
#define MALLOC_FAILURE 1

//---- Node struct ----//
struct Node {
  int id;
  struct Node* next;
};

//---- Functions ----//


//-- Check if Malloc was successful --//
void mallocCheck(struct Node* node){ //Checks if malloc returns NULL, closes down program if so
  if(node == NULL){
    printf("Failure during malloc, shutting down.");
    exit(MALLOC_FAILURE);
  }
}

//-- Function used to insert data to a node --//
void createNode(struct Node* node, int enteredId, struct Node* nextNode){ //Creates each node in list
  node -> id = enteredId;
  node -> next = nextNode;
}


//-- Prints entire list and stops at NULL --//
void printList(struct Node* head){//Loops through every item in the list and prints until it reaches NULL 
  struct Node* current = head;
  
  while(current != NULL){
    printf("%d -> ", current -> id);
    current = current -> next;
  }
  printf("NULL\n");
}


//-- Loops through each element in a list and frees them from heap --//
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


//-- Loops through list and counts how many nodes exist --//
int countNode(struct Node* head){
  struct Node* nextNode;
  struct Node* current = head;
  int nodeCount = 0;

  while(current != NULL){ // While current isn't null, add one to the node count
    nextNode = current -> next;
    nodeCount++;
    current = nextNode;
  }
  printf("Finished counting, the total amount of nodes is %d\n", nodeCount);
  return nodeCount;
}

//-- Insert to the end of a linked list --//
void insertEnd(struct Node* head){
  // Needs work !
  struct Node* current = head;
  
  char userId[5];
  printf("Enter the id you want the new node to be: ");
  scanf("%4s", userId);
  int validatedUserId = atoi(userId);

  struct Node* newNode = malloc(sizeof(struct Node));
  mallocCheck(newNode);
  createNode(newNode,validatedUserId,NULL); // New node is created and given data
  
  while(current != NULL){
    if(current -> next == NULL){ // If the next node is NULL then set the next pointer of current node to the new node 
      current -> next = newNode;
      printf("Added a new node !\n");
      break;
    } else {
      current = current -> next;
    }
  } 
}

//-- Delete a node --//
void deleteNode(struct Node* head){
  struct Node* currentNode = head;

  char tempInput[5];
  int nodeChosen;
  printf("Enter the node you want to delete:\n");
  scanf("%4s", tempInput);
  nodeChosen = atoi(tempInput);

  if(nodeChosen == 1){
    printf("Node chosen can't be the head of the linked list\n");
  } else{

    while(currentNode -> id != nodeChosen){ //loops through linked list until currentNode id is the node chosen for deletion
      struct Node* tempNode = currentNode -> next;

      if(tempNode -> id == nodeChosen){ //if the id is the same as the chosen node
        currentNode -> next = tempNode -> next; // The next pointer for the current pointer will be the next pointer for the tempNode
        tempNode -> next = NULL; // tempNode pointer is now updated to be null
        free(tempNode); // free from memory
        break;
      }
      currentNode = currentNode -> next; //makes the current node the next node in the list
    }
  }
}
