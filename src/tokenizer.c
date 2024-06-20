#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
int main(){
  void str_cpy(char *arr, char* temp ){

    while(*temp){
      //
      *arr = *temp;

      arr++;

      temp++;

    }

  }

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
    if(c != ' ' ||c != '\t'){
      return 1;
    }else{
      return 0;
    }
  }

  /* Returns a pointer to the first character of the next 
     space-separated token in zero-terminated str.  Return a zero pointer if 
     str does not contain any tokens. */
  char *token_start(char *str){
   
  }

  /* Returns a pointer terminator char following *token */
  char *token_terminator(char *token){
    char *temp = token;
    token+=1;
    while(*token){
      token++;
      temp++;
    }
    return temp;
  }

  /* Counts the number of tokens in the string argument. */
  int count_tokens(char *str){
    
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
    int str_length = str_len(str);

    int max_words = 3; // Assuming a maximum of 3 words

    int max_word_length = 100; // Maximum length of each word



    // Allocate memory for the array of strings

    char **arr = (char **)malloc(max_words * sizeof(char *));

    for (int i = 0; i < max_words; i++) {

      arr[i] = (char *)malloc(max_word_length * sizeof(char));

    }



    char temp[max_word_length];

    int i = 0;

    int j = 0;

    int m = 0;



    for (i = 0; i <= str_length; i++) {

      if (str[i] != ' ' && str[i] != '\0') {

	temp[j] = str[i];

	j++;

      } else {

	temp[j] = '\0'; // Null-terminate temp to make it a valid string

	str_cpy(arr[m], temp); // Copy the word to arr

	m++;

	j = 0;

      }

    }



    return arr;
  }
  /* Prints all tokens. */
  void print_tokens(char **tokens);

  /* Frees all tokens and the vector containing themx. */
  void free_tokens(char **tokens);

  return 0;
}
