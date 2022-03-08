/*************************************************
   CS 222 System Programming
   Parker Tribble
   Functions source file for lab7

   Contains function definitions for functions
   prototyped in lab7_functions.h

**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "lab7_functions.h"


/********* F U N C T I O N   D E F I N I T I O N S *********/

// Reads string from standard input and dynamically allocates space
// Assumes user input string terminates with '\n' (ENTER)
char *readCmd() {
	char* temp;
	char character, junk;
	int i = 0;
	temp = (char*)malloc(sizeof(char)); //allocating space
	scanf(" %c", &character);
	while (character != '\n') { //reading in characters until the next one is a new line
		temp[i++] = character;
		temp = (char*)realloc(temp, (i + 1) * sizeof(char)); //allocating space for new char
		scanf("%c", &character);
	}
	temp[i] = '\0';
	return temp;
}

// Print contents of entire list
//   Each number takes the whole line
//   Print "List is empty" when list is empty
void printList(LLnode *list) {
	if (list == NULL) {
		printf("List is empty\n");
	}
	else {
		LLnode* current = list;  //assigning current to node

		while (current != NULL) {
			printf("%d\n", current->value);  // print valuse of current node
			current = current->next; //changing the pointer of current
		}
	}
	
}


/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Frees entire list before end of program to avoid memory leaks
void freeList(LLnode *list) {
	LLnode *before = NULL;	// "Previous" node
	LLnode *current = list;	// "Current" node
	before = NULL;
	current = list;

	// If current node exists, remove it
	while (current != NULL) {
		before = current;
		current = current->next;
		free(before);
	}
}

/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Add integer to list and return list's starting address
LLnode *addNode(LLnode *list, int v) {
	LLnode *newNode;

	// Allocate space for new node; exit if error
	newNode = (LLnode *)malloc(sizeof(LLnode));
	if (newNode == NULL) {
		printf("Error: could not allocate new node\n");
		freeList(list);
		exit(0);
	}

	newNode->value = v;		// Copy value to new node
	newNode->next = list;	// next points to old beginning of list
	return newNode;
}

/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Find node in list and return pointer
//   (or NULL if not found)
LLnode *findNode(LLnode *list, int v) {
	// Create pointer to start of list
	LLnode *n = list;

	// Loop to visit all nodes in list
	while (n != NULL) {
		// For current node:
		//   a. Check if data you want is in that node --> return address if so
		if (v == n->value) {
			return n;
		}

		//   b. Otherwise, move to the next node
		n = n->next;
	}

	// If data isn't found, return NULL
	return NULL;
}

/* THIS FUNCTION IS GIVEN, DO NOT MODIFY */
// Delete node from list (if present)
//   Return starting address of list when done
LLnode *delNode(LLnode *list, int v) {
	LLnode *prev = NULL;
	LLnode *cur = list;

	while (cur != NULL && v != cur->value) {
		prev = cur;
		cur = cur->next;
	}

	if (cur == NULL) {		// No match--went through entire list
		printf("%d not found in list\n", v);
		return list;
	}
	else {			// Match found (v == cur->value), so delete cur node

		if (cur == list)		// Match found in first node
								// Alternate condition: prev == NULL
			list = cur->next;

		else		// Match found outside of first node
			prev->next = cur->next;

		free(cur);
		printf("%d was deleted from list\n", v);
		return list;
	}
}

// Keep list sorted in ascending order
//   and add integer; return pointer to
//   start of list
LLnode *addSortedNode(LLnode *list, int v) {
	LLnode* newNode;
	newNode = (LLnode*)malloc(sizeof(LLnode)); // Allocate memory for new node
	if (newNode == NULL) { //checking for error
		printf("Error: could not allocate new node\n");
		freeList(list); //freeing the node
		exit(0);
	}
	newNode->value = v;        //assign val to new node
	LLnode* current = list;
	if (current == NULL || current->value >= newNode->value) //deals with node at the end of list
	{
		newNode->next = current;
		list = newNode;
		return newNode;
	}
	else
	{
		while (current->next != NULL && current->next->value < newNode->value) 
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	return list;
}

// Find node in sorted list and return pointer
//   (or NULL if not found)
LLnode *findSortedNode(LLnode *list, int v) {
	LLnode* current = list; //decleration
	while ((current != NULL) && (current->value <= v)) {
		if (current->value == v)    // if data found then return it
			return current;
		current = current->next;
	}
	return NULL;    // error
}

// Delete node from sorted list (if present)
//   Return starting address of list when done
LLnode *delSortedNode(LLnode *list, int v) {
	LLnode* current, * delete;    //decleration
	current = list; //assignment
	if (current != NULL) //looks for empty list
	{
		if (current->value == v) // checks for if v is current value
		{
			list = current->next;
			free(current);  //free the mem of current node
			printf("%d was deleted from list\n", v);
			return list;
		}
		while (current->next != NULL && current->next->value >= v)  // loops through all nodes in the list
		{
			if (current->next->value == v)
			{
				delete = current->next;
				current->next = current->next->next;
				free(delete);    // frees the memory of node to be deleted
				printf("%d was deleted from list\n", v);
				return list;
			}
			current = current->next;
		}
		printf("%d not found in list\n", v);
	}
	return list;
}
