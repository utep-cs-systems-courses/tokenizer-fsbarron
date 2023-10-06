#include <stdio.h>
#include <stdlib.h>
#include "history.h"




//here we  initialize and return an empty list
List* init_history(){
  List *list = (List*)malloc(sizeof(List));//allocate memory
  if(list){
    list->root = NULL;//initialize pointer to null
  }
  return list;//returned initialized list
}

//here we add a new item to the history list 
void add_history(List *list, char *str){
  Item *newItem = (Item*)malloc(sizeof(Item));//allocate the memory for a new history item
  newItem->id = 0;//we initialize id to 0
  newItem->str=str;//we set the string pointer to input string
  newItem->next = NULL;//next pointer is initialized ot null

  if(list->root == NULL){
    list->root = newItem;//if our list is empty we set the pointer to a new item
  }
  //Traverses through list
  else{
    Item *current = list->root;
    while(current != NULL){
      current = current->next;//here we traverse lis to find new item
    }
    //Sets pointer of last item to new item
    current->next = newItem;
  }
}


//here we get the string of given id from list
char* get_history(List *list, int id){
  Item* current = list-> root;
  
  while(current != NULL){
    //Checks if id matches
    if(current->id == id){
      return current-> str;//we return item if id matches
    }
    current = current->next;//we move to next item
  }
  return NULL;//return null if no item is found
}
void print_history(List *list){ 
  Item* current = list->root;//declare pointer item to root
  //Loops through LL
  while(current != NULL){ //we print id and string of each item
    printf("ID: %d, String: %s\n", current->id, current->str);
    current = current->next;//now we move to next item
  }
}

void free_history(List *list){
  Item* current = list->root;//declare ponter curr to root
  while(current != NULL){
    Item* next = current->next;
    free(current->str); //free memory allocated from string
    free(current);//free memory allocated from item
    current = next;//move to next item
  }
  free(list);//we free memory allocated for list
}
