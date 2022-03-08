/*************************************************
   CS 222 System Programming
   Parker Tribble
   Main program for lab7: Dynamic memory allocation
   and data structures

   Works with singly linked list, which is defined
   in separate file
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab7_functions.h"	 // Contains function prototypes

int main() {
	LLnode* mylist = NULL;   // Node pointer to start of linked list
	LLnode *targetNode;      // Used when finding nodes
	char *cmd = NULL;	     // Input string command
	int inVal;			     // Input value to be added/found/deleted
	char sorted;			 // 'Y' or 'N': test to see if list should be sorted
	char junk;				// Used to hold junk characters 

	/* Loop to determine whether the list is sorted or unsorted */
	do {
		// Sorted list or unsorted prompt
		printf("Use sorted linked list? (Y/N): ");
		// Read in the choice
		scanf("%c", &sorted);
		// Check the validity of the choice
		if (sorted !='Y' && sorted != 'y' && sorted != 'N' && sorted != 'n') {
			printf("Invalid choice %c\n\n", sorted);
			do { // clear the line
				scanf("%c", &junk);
			} while (junk != '\n');
		}
	} while (sorted !='Y' && sorted != 'y' && sorted != 'N' && sorted != 'n');
	
	/* The rest of the program will stick with a choice: sorted or unsorted */

	// Loop to check and execute the user's command
	//   Only breaks out when receives "exit"
	do {
		printf("\nEnter command: ");
		cmd = readCmd();		
	
		// Add integer to list
		// CHANGE THE CONDITION 0 and FINISH BRANCH BODY
		if (strncmp("add", cmd, strlen(cmd)) == 0) { //compares cmd with add to start the add function
			printf("Enter number to be added: ");
			scanf(" %d", &inVal); //reading in values
			if (sorted == 'Y' || sorted == 'y') { //sorted
				mylist = addSortedNode(mylist, inVal);
			}
			else if (sorted == 'n' || sorted == 'N') { //not sorted
				mylist = addNode(mylist, inVal);
				}
			do {
				scanf("%c", &junk); //cleaning out the pipeline
			} while (junk != '\n');
		}

		// Delete node from list
		else if (strncmp("delete", cmd, strlen(cmd)) == 0) { //compares cmd with delete to start the delete function
			printf("Enter number to be deleted: ");
			scanf(" %d", &inVal); //reading in values
			if (sorted == 'Y' || sorted == 'y') { //sorted
				delSortedNode(mylist, inVal);
			}
			else if(sorted == 'n' || sorted == 'N') {//not sorted
				delNode(mylist, inVal); 
			}

			do { // cleaning out the pipeline
				scanf("%c", &junk);
			} while (junk != '\n');
		}

		// Find node in list
		else if (strncmp("find", cmd, strlen(cmd)) == 0) { // comparing cmd to find to start the find function
			printf("Enter number to be found: ");
			scanf(" %d", &inVal); //reading in values
			if (sorted == 'Y' || sorted == 'y') { //sorted
				if (findSortedNode(mylist, inVal) == NULL) //node with given value was not found 
					printf("%d not found in list\n", inVal);
				else
					printf("%d found in list\n", inVal); 
			}
			else if (sorted == 'n' || sorted == 'N') { //not sorted
				if (findNode(mylist, inVal) == NULL)  //node with given value not found
					printf("%d not found in list\n", inVal);
				else
					printf("%d found in list\n", inVal);
			}
			do { // clear the line
				scanf("%c", &junk);
			} while (junk != '\n');
		}

		// Print contents of entire list
		else if (strncmp("print", cmd, strlen(cmd)) == 0) { //compare cmd to print to start the print function
			printList(mylist);
		}

		// Invalid command
		else if (strncmp("exit", cmd, strlen(cmd)) != 0) { //compare cmd to exit to end the program
			printf("Invalid command %s\n", cmd);
		}

	} while (strcmp(cmd, "exit") != 0);
		
	freeList(mylist); //freeing the list!!!!!!!!!!!!!!!!
	return 0;
}


