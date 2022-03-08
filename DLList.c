/*************************************************
 *  CS 222: System Programming
 *  Elizabethtown College
 *  P. Li
 *  DLList source file for the 3rd project
 *  Contains function definitions
 *************************************************

    ********************************************** 
	STUDENTS MUST WRITE CODE TO CORRECTLY COMPLETE
    EACH FUNCTION DEFINITION BELOW, BUT SHOULD NOT
	MODIFY THE RETURN TYPE, NAME, OR ARGUMENTS OF
	ANY FUNCTION
	**********************************************

**************************************************/

/******************************************************************
* Parker Tribble
* 5/3/2020
*tribblep@etown.edu
********************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "DLList.h"

// Reads string from standard input and dynamically allocates space
// Assumes user input string terminates with '\n' (ENTER)
char *readLine() {
	/**** CS 222 Project 3 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	char* a; //variable delctation
	char c;
	int i = 0;
	a = (char*)malloc(sizeof(char)); //dynamically allocating space for line being read in
	scanf("%c", &c); //scaning in the string
	while (c != '\n') {  // Loops through the characters in string
		a[i++] = c;   //moves through character array a
		a = (char*)realloc(a, (i + 1) * sizeof(char));  // increase size of memory for character
		scanf("%c", &c);    // scan next character
	}
		a[i] = '\0'; //null terminator
	return a; //returning the string a contatining the word given by user
}

// Find node containing word
// Return pointer to node, or NULL if nothing found
DLNode *findNode(DLList *list, char *str) {

	/**** CS 222 Project 3 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	DLNode* current = list->firstNode; //initalizing pointer, pointing at the first node of list
	while (current != NULL) { //while node isnt null
		if (strcmp(current->word, str) == 0)  //compairing the current node's word to given string
		{
			return current; //returns current node becuase word was found
		}
		current = current->next; //moving to next node because word was not found
	}
	return NULL; //returns NULL becuase nothing was found
}

// Add new node to list containing str
void addNode(DLList* list, char* str) {
	/**** CS 222 Project 3 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	DLNode* newNode = (DLNode*)malloc(sizeof(DLNode)); //creating new node with memory space
	newNode->word = str; //initailizing the word in the node
		if (list->firstNode == NULL) //if there is no first node
		{
			list->firstNode = list->lastNode = newNode; // then new node is first node
		}
		else 
		{
			DLNode* curr = list->firstNode; //current node pointer points to first node in list
			do {
				if (strcmp(curr->word, str) < 0)  //compare string in current node to provided string str
				{
					curr = curr->next; // moving curr to the next node in list
				}
				else if (curr == list->firstNode)  //if current node is equal to the first node
				{
					curr->prev = newNode; //re-establishing the list 
					newNode->next = curr;
					list->firstNode = newNode; //setting new node to firstNode
					return; //returns to leave loop
				}
				else 
				{
					newNode->prev = curr->prev; //reestablishing list order
					newNode->next = curr;
					curr->next->prev = newNode;
					curr->prev = newNode;
					return; //return to leave loop 
				}
			} while (curr != NULL);
			list->lastNode->next = newNode; //reestablishing list if the new node needs to be last
			newNode->prev = list->lastNode;
			list->lastNode = newNode; //making new node the lastNode
		}
}

// Delete node containing word from list if it is present
	void delNode(DLList * list, char* str) {
		/**** CS 222 Project 3 ****/
		/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
		DLNode* toDelete; //declaring pointer
		toDelete = findNode(list, str); //
		if (toDelete != NULL) //if pointer is not null
		{
			if ((toDelete->next == NULL) && (toDelete->prev == NULL)) //if the node to be deleted is the only node
			{
				list->firstNode = list->lastNode = NULL; //setting everything to null because list is empty
			}
			else if (toDelete == list->lastNode) //if node to be deleted is the last Node
			{
				list->lastNode = toDelete->prev; //re-establishing the lastNode 
				list->lastNode->next = NULL;//re-establishing the lastNode pointers
			}
			else if (toDelete == list->firstNode) //if node to be deleted is the firstNode
			{
				list->firstNode = toDelete->next; //re-establishing firstNode
				list->firstNode->prev = NULL; //re-establishing firstNode's pointers
			}
			else 
			{
				toDelete->prev->next = toDelete->next; //reestablishing order of list
				toDelete->next->prev = toDelete->prev;
			}
			free(toDelete->word); //freeing up memory 
			free(toDelete);
		}
	}


// Print contents of list, or message
void printList(DLList *list) {
	/**** CS 222 Project 3 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
		DLNode* curr = list->firstNode; //curr is pointer to first node in list
		if (curr == NULL) //if current node is null
		{
			printf("List is empty\n"); //notifiy user that there are no nodes
		}
		 else
		{
			printf("Contents of list:\n"); 
			while (curr != NULL) //while loop to print the contents of the list
			{
				 printf("%s\n", curr->word);
				 curr = curr->next;
			 } 
		 }
}
