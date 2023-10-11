#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
/*
int main()
{
    int exit = 1;
    List *historyList = init_history();

    do {
        printf("Make your selection\n 1. Tokenize 2. Print History 3. Get History 4. Quit (Enter 1, 2, 3, or 4)\n");
        printf("> ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character left in input buffer
        
        switch(choice) {
            case 1: {
	      char tokens[100];//declare character array
	      printf("Enter a string to tokenize:\n> ");//read input from user
                fgets(tokens, 100, stdin);
                char **t = tokenize(tokens);
                add_history(historyList, tokens);//add input to history list
                print_tokens(t);//print tokens 
                free_tokens(t);		
            } 
            case 2:
                print_history(historyList);
                break;
            case 3: {
                printf("Enter ID to retrieve history:\n> ");
                int id;
                scanf("%d", &id);
                getchar(); // Consume newline character left in input buffer
                char *history = get_history(historyList, id);
                if (history != NULL) {
                    printf("History ID %d: %s\n", id, history);
                } else {
                    printf("History ID %d not found.\n", id);
                }
                break;
            }
            case 4:
                exit = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (exit);

    free_history(historyList);
    return 0;
}

*/

int isSame(const char  *string1, const char  *string2){
  while(*string1 != '\0' && *string2 != '\0'){//iterate until we encounter a null terminator 
    if(*string1 != *string2)
      return 0;
    string1++;//move pointers to nect characters 
    string2++;
  }//we separate the characters at current position if they're not the same
  return (*string1 == '\0' && *string2 == '\0');
}

int main(){

  printf("Welcome! input a string to tokenize or type 'exit'\n");
  while(1){
    char input[100];

    scanf("%s", input);
    // if user inputs exit we break the loop and exit
    if(isSame(input, "exit")){
              break;
            }
            printf("%s\n", input);
            }
    return 0;
  }

