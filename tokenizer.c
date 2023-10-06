#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

//here we return 1 if character is a space
int space_char(char c){
  return (c== ' ' || c == '\t');
}

//here we return 1 if the character is not a space
int non_space_char(char c){
  return !space_char(c);

}

//here we move the pointer to the next character and we return the pointer 
//iterates until reaching null
char * token_start(char *s){
  while(*s !='\0' && space_char(*s)){
    s++;
}
  if(*s == '\0'){
    return NULL;//we return null if our string has spaces
  }

  //end
  return s;
}

//here we move the pointer until we find a space or the end of token
//here we return the pointer to a space character 
char *token_terminator(char *token){
  while(*token && *token !='\0'){
    token++;
  } 
  return token;
}

//here we count the number of tokens
//and we also return the token count 
int count_tokens(char *s){
  int count = 0;//initialize number of tokens
  char *token = token_start(s);//we get the starting position of first token
  while (token){//loop until there's no more tokens
    count++;//increment count when token is found
    token = token_terminator(token);//finds end
    token = token_start(token);//we move pointer to start of next token, if it points to string it will be null
  }
  return count;//return count of tokens
}



// Handles memory allocation

char *copy_str(const char *input, int length) {
    char *copy = (char *)malloc(length + 1);
    if (copy == NULL) {
        // Handles memory allocation                                                                                                                              
        return NULL;
    }
    strncpy(copy, input, length);
    copy[length] = '\0';  //here we copy length                                                                                                                   
    return copy;
}


//here we tokenize the string
//we also return an array
 char **tokenize(char *s){
   int tokenCount = count_tokens(s);//count number of tokens
   char **tokens = (char**)malloc((tokenCount + 1) * sizeof(char*));  //allocate memory for array of pointers (characters) and number of elements in array
  //allocate memory for array to store tokens
  char *tokenStart = token_start(s);//get starting position of first token
  for(int i=0; i < tokenCount; i++){//iterate through tokens and tokenize
    char *tokenEnd = token_terminator(tokenStart);//find the end position of token
    int tokenLength = tokenEnd - tokenStart;//calculate length of current token
    tokens[i] = copy_str(tokenStart, tokenLength);//allocate memory of current token and copy characters
    tokenStart = tokenEnd;//move pointer to next character 
    if(tokenStart != NULL){    
    tokenStart = token_start(tokenStart);
  }
 }
  tokens[tokenCount] = NULL;//here we terminata the array 
  //return array of tokens
  return tokens;
}


//here we iterate through array until we get a null pointer 
void free_tokens(char **tokens){
  int i=0;
  while(tokens[i]!= 0){
    free(tokens[i]);//now we free the memory allocated for string
    i++;
      }
  free(tokens);//now we free the memory allocated for
}


int count_words(char *s) {
  int count = 0;
  int insideWord=0;//indicates if we are inside
  //iterate through string and we count
  while(*s){
    if(space_char(*s)&&insideWord){//if the character is in a space inside the word we are at the end
      insideWord = 0;
    }
    else if(!space_char(*s)&& !insideWord){
      count++;//increment count
      insideWord =1;//indicates we are in a word
    }
    s++;//move to next character
  }  
  return count;    
}

//here we iterate through string until nonspace character is found
char *find_word_start(char *s) {
  while(*s && space_char(*s)){
    s++;//now we move the pointer to the next character
  }
  return s;//now we return the pointer to the first nonspace character
}

//here we iterate until the end of a string is found or a space character
char *find_word_terminator(char *token) {
  char *s = token;
  while(*s && non_space_char(*s)){
    s++;//move the pointer to the next character
  }
  return s;//return the pointer to the space character 
}

//here we determine if the character is valid
int is_valid_character(char c) {
  if((c>= 'a' && c <= 'z') || (c>='A' && c <= 'Z')){
    return 1; //return 1 if character is valid
  } else{
    return 0;//returns 0 if it's not valid
  }
}


 
