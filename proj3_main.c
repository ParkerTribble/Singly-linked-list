/*************************************************
 *  CS 222: System Programming
 *  Elizabethtown College
 *  P. Li
 *  Main program for the 3rd project
 *  Working with dynamic memory allocation
 
    **********************************************
    STUDENTS MUST WRITE CODE TO CORRECTLY COMPLETE
    THE MAIN FUNCTION BELOW. DO NOT MODIFY THE
    GIVEN FUNCTION readline()
    **********************************************
 
 *************************************************/
 /******************************************************************
 * Parker Tribble
 * 5/3/2020
 *tribblep@etown.edu
 ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>             // Header file for string functions
#include "DLList.h"				// User-defined header file

int main() {
	DLList myList = {NULL, NULL};	// Doubly-linked list used throughout program
	DLList* MyList = &myList;		//pointer to myList initialized
									// Since list is empty, firstNode and lastNode are
									//    both initialized to NULL
	char *cmd = NULL;				// Input command
	char *word = NULL;				// Input word 

	do {
		printf("\nEnter command:  ");
		cmd = readLine();		// Read string from standard input
	
		// Add word to list
		if (strcmp(cmd, "add") == 0) {
			printf("Enter word to be added:  ");
			word = readLine();
            /**** CS 222 Project 3 ****/
            /***********************************
             ADD YOUR CODE HERE TO ADD A NODE
             ***********************************/
			addNode(MyList, word); //calling addNode function 
			//passing through MyList pointer and word pointer 
			
		}

		// Delete word from list
		else if (strcmp(cmd, "delete") == 0) {
			printf("Enter word to be deleted:  ");
			word = readLine();
            /**** CS 222 Project 3 ****/
            /***********************************
             ADD YOUR CODE HERE TO DELETE A NODE
             ***********************************/
			delNode(MyList, word);//calling delNode function 
			//passing through MyList pointer and word pointer 
            
		}

		// Find word in list
		else if (strcmp(cmd, "find") == 0) {
			printf("Enter word to be found:  ");
			word = readLine();
            /**** CS 222 Project 3 ****/
            /***********************************
             ADD YOUR CODE HERE TO FIND A NODE
             ***********************************/
			DLNode *found;							//declaring pointer 
			found = findNode(MyList, word);			//setting pointer equal to the node retruned by findNode function
			if (found == NULL)						//if null, no word was found
				printf("%s not found in list\n", word); //notify user
			else                                       //else the word was found
				printf("%s found in list\n", word);  // notfiy user 
		}

		// Print contents of entire list
        else if (strcmp(cmd, "print") == 0){
            /**** CS 222 Project 3 ****/
            /***********************************
             PRINT THE CONTENTS FROM YOUR LIST
             ***********************************/
			printList(MyList); //calling printlist function 
								//passing through MyList pointer
        }

		// Invalid command
		else if (strcmp(cmd, "exit") != 0)
			printf("Invalid command %s\n", cmd);

	} while (strcmp(cmd, "exit") != 0);

	return 0;
}


