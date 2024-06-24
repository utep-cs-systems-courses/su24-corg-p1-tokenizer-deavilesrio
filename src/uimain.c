#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
    char menu;
    char s[100];
    char c;
    char **arr;
    List *list;
    while(1){
        printf("Tokenizer: Press t, History: Press h\n");
        if (scanf("%c", &menu) != 1) {
            fprintf(stderr, "Error reading input for menu\n");
            return 1; // Exit with an error code
        }
        // Clear the input buffer to remove any leftover characters, especially newlines
        int ch;
        while ((ch = getchar()) != '\n');

        if(menu == 't'){
            while(1){
            printf("Write something: ");
            if (fgets(s, sizeof(s), stdin) == NULL) {
                fprintf(stderr, "Error reading input for string\n");
                return 1; // Exit with an error code
            }
            // char *last_char = token_terminator(s);
            // printf("Last character: '%c'\n", *last_char);   
            // int count = count_tokens(s);
            // printf("Number of tokens: %d\n", count);     
            arr = tokenize(s);
            if (arr == NULL) {
                printf("Tokenization failed\n");
                return 1;
            }
            
            print_tokens(arr);
            add_history(&list, s);
            printf("\n");
            printf("Quit: N/n, Continue: Any other key\n");
            scanf(" %c", &c);  // Added space before %c to consume any whitespace characters

            if (c == 'N' || c == 'n') {
                // Free allocated memory
                break;
            }
            // Clear the input buffer to remove any leftover characters, especially newlines

            ch;

            while ((ch = getchar()) != '\n');
            }

        }else if(menu == 'h'){
            int selection;
            printf("String History: 1\nHistory by id: 2\n>");
            scanf("%d", &selection);
            if(selection == 1){
                
                print_history(&list);
            }
            else if(selection == 2){
                int id;
                printf("Select id:\n>");
                scanf("%d", &id);
                get_history(&list, id);
            }
        }else{
            printf("Incorrect key\n");
        }
        c = ' ';
        printf("Quit: N/n, Continue: Any other key\n");
            scanf(" %c", &c);  // Added space before %c to consume any whitespace characters

            if (c == 'N' || c == 'n') {
                // Free allocated memory
                break;
            }
            // Clear the input buffer to remove any leftover characters, especially newlines

            ch;

            while ((ch = getchar()) != '\n');
    }
    // Free allocated memory
    free_tokens(arr);

    return 0;
}
