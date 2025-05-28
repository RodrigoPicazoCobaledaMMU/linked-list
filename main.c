//---- Libraries ----//    
#include <stdio.h>       
#include <stdlib.h>      
#include <string.h>      
#include <stdbool.h>

//---- External C files ----//    
#include "linkedList.c"

//---- Defines ----//    
#define MALLOC_FAILURE 1 
#define SUCCESS 0        

//---- Main ----//
int main () {  
  //---- Creating list header ----//
  struct Node* head = malloc(sizeof(struct Node));
  mallocCheck(head); //Check for malloc failure
  createNode(head, 1, NULL); // Adding node items

  //---- Menu ----//
  bool isMenu = true;
  while(isMenu){
    char tempInput[2];

    printf("\n\nMenu:\n-----\n");
    printf("1.) Print list\n");
    printf("2.) Count nodes\n");
    printf("3.) Insert node at end\n");
    printf("4.) Delete node\n");
    printf("5.) Quit\n");

    printf("Please enter your selected option:");
    scanf("%1s", tempInput);
    int menuOption = atoi(tempInput);
    
    switch(menuOption){
      case 1:
        printList(head);
        break;
      case 2:
        countNode(head);
        break;
      case 3:
        insertEnd(head);
        break;
      case 4:
        deleteNode(head);
        break;
      case 5:
        freeList(head);
        exit(SUCCESS);
      default:
        printf("Input isn't valid in the menu,please try again\n");
    }
  }
  //---- Exit ----//    
  return SUCCESS;
}
