#include <stdio.h>

#include <stdlib.h> // For memory allocation functions
#include "tokenizer.h"


int main() {

  char s[100];

  char c;
  char **arr;
  // s = (char *)malloc(sizeof(char) * 100); // Allocate memory for the string



  if (s == NULL) {

    printf("Memory allocation failed\n");

    return 1;

  }



  while (1) {

    printf("Write something: ");

    fgets(s, 100, stdin);
    arr = tokenize(s);







    for (int k = 0; k <= 3; k++) {

      if(arr[k] != NULL){
	printf("%s ", arr[k]);
      }
    }
    // printf("You wrote: %s\n", s);
    printf("\n");



    // Free allocated memory

    for (int i = 0; i < 3; i++) {

      free(arr[i]);

    }

    free(arr);
    printf("Quit: N/n, Continue: What ever key\n");



    scanf("%c", &c); // Added space before %c to consume any whitespace characters

    if (c == 'N' || c == 'n') {

      break;

    }

    // Clear the input buffer to remove any leftover characters, especially newlines

    int ch;

    while ((ch = getchar()) != '\n');

  }



  // Free allocated memory before exiting

  // free(s);



  return 0;

}

