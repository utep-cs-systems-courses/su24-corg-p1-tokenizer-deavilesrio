#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


void str_cpy(char* dest, char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}
/* Initialize the linked list to keep the history. */
List* init_history(){
    List *history;
    return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
    // Allocate memory for the new item
    Item *newItem = (Item *)malloc(sizeof(Item));
    if (newItem == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Duplicate the string to avoid issues with the original string
    newItem->str = (char *)malloc(str_len(str) + 1);
    str_cpy(newItem->str, str);
    if (newItem->str == NULL) {
        free(newItem);
        perror("Failed to allocate memory for string");
        exit(EXIT_FAILURE);
    }

    newItem->next = NULL;

    // If the list is empty, add the new item as the root with ID 1
    if (list->root == NULL) {
        newItem->id = 1;
        list->root = newItem;
        return;
    }

    // Traverse to the end of the list
    Item *current = list->root;
    int id_count = 1; // Initialize ID counter
    while (current->next != NULL) {
        current = current->next;
        id_count++;
    }

    // Set the ID for the new item
    newItem->id = id_count + 1;

    // Add the new item to the end of the list
    current->next = newItem;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item *current = list->root;
    while (current != NULL) {
        //printf("ID: %d\n", current->id);
        
        if(id == current->id){
            printf("ID: %d, String: %s\n", current->id, current->str);
            break;
        }
        current = current->next;
        
    }
}

/*Print the entire contents of the list. */
void print_history(List *list){
    Item *current = list->root;
    while (current != NULL) {
        printf("ID: %d, String: %s\n", current->id, current->str);
        current = current->next;
    }
    

}

/*Free the history list and the strings it references. */
void free_history(List *list){
    while(list->root->next != NULL){
        list->root->str = "";
        free(list->root);
    }
    free(list);
}