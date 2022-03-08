

/*************************************************
 *  CS 222: System Programming
 *  Elizabethtown College
 *  P. Li
 *  Header file for project 3
 *  Contains structure definitions,
 *  and function prototypes

********DO NOT MODIFY THIS FILE ********

**************************************************/

#ifndef DLList_h
#define DLList_h

/********* S T R U C T U R E   D E F I N I T I O N S *********/
// Node in doubly-linked list
typedef struct DLN {
	struct DLN *prev;		// Pointer to previous list element
	struct DLN *next;		// Pointer to next list element
	char *word;
} DLNode;

// Actual doubly-linked list
typedef struct {
	DLNode *firstNode;	// Pointer to first node in list
	DLNode *lastNode;	// Pointer to last node in list
} DLList;


/********* F U N C T I O N   P R O T O T Y P E S *********/

char *readLine();  // Reads string from input and dynamically allocates space
DLNode *findNode(DLList *list, char *str);		// Find node containing str
void addNode(DLList *list, char *str);			// Add new node to list containing str
void delNode(DLList *list, char *str);			// Delete node containing str from list
void printList(DLList *list);					// Print contents of list

#endif
