/*
CSCI 104: Homework 2 Problem 6
Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split (Node*& in, Node*& odds, Node*& evens) 
{
	// If there is no more numbers to split, then stop.
	// BASE CASE
	if(in == NULL) 
	{
		odds = NULL;
		evens = NULL;
		return;
	}
	//Otherwise, recurse
	else if (in != NULL)
	{
        //If the number is odd
		if(in->value % 2 == 1) 
		{
			//Take a copy of input nodes.
		    Node* nextodd = in;
		    //Take a copy for current+1 ~ end nodes.
		    Node* temp = in->next;
		    //Take the current number(only) and delete the rest.
		    nextodd->next = NULL;
		    //Put this "odd" number to our odds list.
		    odds = nextodd;
		    //In the end, for the last node, node->next should be NULL.
		    odds->next = NULL;
		    //Add next odds list after our current list.
		    split(temp, odds->next, evens);
			

		} 

		 //if the element is even
		else 
		{
			 //Take a copy of input nodes.
			Node* nexteven = in;
			 //Take a copy for current+1 ~ end nodes.
			Node* temp = in->next;
			 //Take the current number (only) and delete the rest.
			nexteven->next = NULL;
			 //Put this "even" number to our evens list.
			evens = nexteven;
			 //In the end, for the last node, node->next should be NULL.
			evens->next = NULL;
			 //Add next evens list after our current list.
			split(temp, odds, evens->next);
		}
	}
}	
