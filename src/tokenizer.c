#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

  

  int str_len(char *str ){

    int count = 0;

    while(*str){

      str++;

      count++;

    }

    return count;

  }
  /* Return true (non-zero) if c is a whitespace characer
     ('\t' or ' ').  
     Zero terminators are not printable (therefore false) */
  int space_char(char c){
    if(c == ' ' || c == '\t'){
      return 1;
    }else{
      return 0;
    }
  }

  /* Return true (non-zero) if c is a non-whitespace 
     character (not tab or space).  
     Zero terminators are not printable (therefore false) */ 
  int non_space_char(char c){
    if(c == ' ' ||c == '\t' || c=='\n' || c=='\0'){
      return 0;
    }else{
      return 1;
    }
  }

  /* Returns a pointer to the first character of the next 
     space-separated token in zero-terminated str.  Return a zero pointer if 
     str does not contain any tokens. */
  char *token_start(char *str){
   
  }

  char *token_terminator(char *token) {
    while (*token && *(token + 2)) {
        token++;
    }
    return token;  // This points to the last character before the null terminator
  } 

  /* Counts the number of tokens in the string argument. */
  int count_tokens(char *str){
    int count = 0; //count tokens
    char c; //the char to check 
    char* temp = str;  //temporal
    int istoken = 0;
    while(*temp){
      c = *temp;
       
      if(non_space_char(c) == 1 && istoken == 0){
        
        istoken = 1;
        count++;
      }
      else if(space_char(c) == 1){
        
        istoken = 0;
      }
      
      temp++;
    } 
        
    
    return count;
    
  }

  /* Returns a fresly allocated new zero-terminated string 
     containing <len> chars from <inStr> */
  char *copy_str(char *inStr, short len);

  /* Returns a freshly allocated zero-terminated vector of freshly allocated 
     space-separated tokens from zero-terminated str.

     For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
  */
  char **tokenize(char* str){
     
    int max_word_length = 100;
    int max_words = count_tokens(str);
    char **arr = (char **)malloc(max_words * sizeof(char *)); //Assigns the specific memory for having 10 strings in the array
    if (!arr) return NULL; //if array is empty return null

    for (int i = 0; i < max_words; i++) {
        arr[i] = (char *)malloc(max_word_length * sizeof(char)); //Assigns the specific memory for having 100 characters in each strings of the array
        if (!arr[i]) return NULL;  // Simplified error handling for clarity
    }

    int i = 0, j = 0, m = 0;
    while (str[i]) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') { //if the character of the string is not a space
            arr[m][j++] = str[i]; //save the character of the string str into the character space of the string from the array
        } else { //when a space is found, means it is a complete token
            if (j != 0) { // go inside if j is not 0, meaning it is at the last element
                arr[m][j] = '\0';  // Null-terminate temp to make it a valid string
                m++; // go to the next word space
                j = 0; //restart to the begining
            }
        }
        i++; //next character
    }

    if (j != 0) {
        arr[m][j] = '\0';
        m++;
    }
    arr[m] = NULL;  // Null-terminate the array of strings
    return arr;
  }
  /* Prints all tokens. */
  void print_tokens(char **tokens){
    for (int k = 0; tokens[k] != NULL; k++) {
          printf("%s ", tokens[k]);
      }
  }

  /* Frees all tokens and the vector containing themx. */
  void free_tokens(char **tokens){
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
  }

