/**
  * @file insertion.c
  * @author Amit Prakash (aprakas5) and Dr. Sturgil (dbsturgi)
  * Code to read numbers from standard input inserting them into a list in sorted order as we read them.
  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Node for building our linked list.*/
struct NodeStruct {
  // Value in this node.
  int value;

  // Pointer to the next node.
  struct NodeStruct *next;
};

/** A short type name to use for a node.*/
typedef struct NodeStruct Node;

/**
  * Create a node for the given value and insert it into the given list
  in the proper location to keep the list sorted.  Return an updated
  head pointer.  The head should only need to change if this value gets
  inserted at the front of the list.  Otherwise, you can just return
  the old head pointer.
  * @param head The head node to the list.
  * @param val The value to be inserted into the list.
  * @return The head node created with the new node with the value passed in.
  */
Node *insert( Node *head, int val )
{
    Node **head_ref = &head;
    Node* current;
    Node* new_node = (Node *)malloc(sizeof(Node));
    new_node->value = val;
    new_node->next = NULL;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->value >= new_node->value) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        /* Locate the node before
the point of insertion */
        current = *head_ref;
        while (current->next != NULL
               && current->next->value < new_node->value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return head;
  // ...
}

/**
  * This function has the main functionality of the program.
  * @return This returns the exit status, EXIT_SUCCESS or EXIT_FAIL.
  */
int main()
{
  // Pointer to the head node.
  Node *head = NULL;

  // Read a list of numbers from building a sorted list as we
  // read them.
  int x;
  while ( scanf( "%d", &x ) == 1 ){
    // Insert the new value, and get back the (possibly updated) head pointer.
    head = insert( head, x );
  }

  Node **head_ref = &head;
  Node *current = *head_ref;
  while (current->next != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("%d ", current->value);
  // Print out the list. 
  // ...
  
  // Free all the nodes.
  // ...
  Node *n = head;
  while(n){
   Node *n1 = n;
   n = n->next;
   free(n1);
  }

  return 0;
}
