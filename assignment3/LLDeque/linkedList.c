/***********************************************************
* Author: Chieh Huang
* Email: huangc7@oregonstate.edu
* Date Created: 17/10
* Filename: linkedList.c
*
* Overview:
*	This program is a linked list implementation of the deque and bag ADTs.
*	Note that both implementations utilize a linked list with
*	both a front and back sentinel and double links (links with
*	next and prev pointers).
************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

#ifndef FORMAT_SPECIFIER
#define FORMAT_SPECIFIER "%d"
#endif


/* ************************************************************************
	Structs Link and LinkedList
************************************************************************ */
struct LinkedList
{
    struct Link *first;
    struct Link *last;
};

struct Link
{
    int value;
    struct Link *front;
    struct Link *next;
};

/* ************************************************************************
	Linked List Functions
************************************************************************ */
LinkedList* linkedListCreate()											// Allocates and initializes a linked list
{
    struct LinkedList* head=(LinkedList*)malloc(sizeof(head));
    assert( head!= NULL );
    head->first=NULL;
    head->last=NULL;
    return head;
}

void deletelinkedList(LinkedList* list)				    				// Deallocates every link in the list including the sentinels and deletes the list itself
{
    assert( list != NULL );
    if(list==NULL)
        {
            printf("The list is empty\n");
            return;
        }
    else
    {
        if(isEmptyLinkedList(list))
            printf("List is empty.\n");
        else
        {
            Link* tmp=list->last;
            while(tmp!=NULL)
            {
                list->last=tmp->front;
                free(tmp);
                tmp=list->last;
            }
        }
    }
    free(list);
}

int sizelinkedList(LinkedList* myList)									// Returns the size of the list
{
    assert( myList != NULL );
    int i=0;
    if(isEmptyLinkedList(myList))
        return i;
    else
    {
        Link* tmp=myList->first;
        while(tmp!=NULL)
        {
            i++;
            tmp=tmp->next;
        }
        return i;
    }
}

int isEmptyLinkedList(LinkedList* myList)								// Returns 1 if the list is empty and 0 otherwise
{
    assert( myList != NULL );
    if(myList->first==NULL && myList->last==NULL)
        return 1;
    else
        return 0;
}

void addLinkBefore(LinkedList* list, TYPE value)	            // Adds a new link with the given value before the given list and increments the list's size
{
    assert( list!= NULL );
    Link* tmp=(Link*)malloc(sizeof(tmp));
    tmp->value=value;
    if(isEmptyLinkedList(list))
    {
        list->first=tmp;
        list->last=tmp;
        tmp->front=NULL;
        tmp->next=NULL;
    }
    else
    {
        tmp->next=list->first;
        list->first->front=tmp;
        tmp->front=NULL;
        list->first=tmp;
    }
}

void removeLink(LinkedList* list, TYPE value)					// Removes the given value from the list and decrements the list's size
{
    assert( list!= NULL );
    //printf("remove %d\n",value);
    if(isEmptyLinkedList(list))
        printf("The list is empty.\n");
    else
    {
        Link *tmp,*tmp2;
        tmp=list->first;
        while(tmp!=NULL)
        {
            if(tmp->value==value)
            {
                if(list->first==tmp)
                    list->first=tmp->next;
                if(list->last==tmp)
                    list->last=tmp->front;
                printf("the first %d the last %d\n",list->first->value,list->last->value);
                if(tmp->front!=NULL && tmp->next!=NULL)
                {
                    tmp->front->next=tmp->next;
                    tmp->next->front=tmp->front;
                    tmp2=tmp->next;
                    free(tmp);
                    tmp=tmp2;
                }
                else if(tmp->front==NULL && tmp->next!=NULL)
                {
                    tmp=tmp->next;
                    free(tmp->front);
                    tmp->front=NULL;
                }
                else
                {
                    tmp->front->next=NULL;
                    free(tmp);
                }
            }
            else
                tmp=tmp->next;
        }
    }
    //printf("out remove\n");
}

void printLinkedList(LinkedList* list)									// Prints the values of the links in the list from front to back
{
    if(list==NULL)
        printf("The list is NULL.\n");
    if(isEmptyLinkedList(list))
        printf("The list is empty.\n");
    else
    {
        Link* tmp=list->first;
        while(tmp!=NULL)
        {
            printf("%d ",tmp->value);
            tmp=tmp->next;
        }
        printf("\n");
    }
}


/* ************************************************************************
	Deque Functions
************************************************************************ */
Deque* dequeCreate()							// Allocates and initializes the deque
{
    return linkedListCreate();
}

void deleteDeque(Deque* myDeque)				// Deallocates the data and deletes the deque
{
    deletelinkedList(myDeque);
}

int sizeDeque(Deque* myDeque)					// Returns the size of the deque
{
    return sizelinkedList(myDeque);
}

int isEmptyDeque(Deque* myDeque)				// Returns 1 if the deque is empty and 0 otherwise
{
    return isEmptyLinkedList(myDeque);
}

void addFrontDeque(Deque* myDeque, TYPE value)	// Adds a new link with the given value to the front of the deque
{
    assert( myDeque!= NULL );
    Link *tmp=(Link*)malloc(sizeof(tmp));
    tmp->value=value;
    if(isEmptyDeque(myDeque))
    {
        myDeque->first=tmp;
        myDeque->last=tmp;
        tmp->front=NULL;
        tmp->next=NULL;
    }
    else
    {
        myDeque->first->front=tmp;
        tmp->next=myDeque->first;
        tmp->front=NULL;
        myDeque->first=tmp;
    }
}

void addBackDeque(Deque* myDeque, TYPE value)	// Adds a new link with the given value to the back of the deque
{
    assert( myDeque!= NULL );
    Link *tmp=(Link*)malloc(sizeof(tmp));
    tmp->value=value;
    if(isEmptyDeque(myDeque))
    {
        myDeque->first=tmp;
        myDeque->last=tmp;
        tmp->front=NULL;
        tmp->next=NULL;
    }
    else
    {
        myDeque->last->next=tmp;
        tmp->front=myDeque->last;
        tmp->next=NULL;
        myDeque->last=tmp;
    }
}

TYPE frontDeque(Deque* myDeque)		    		// Returns the value of the link at the front of the deque
{
    assert( myDeque!= NULL );
    return myDeque->first->value;
}

TYPE backDeque(Deque* myDeque)					// Returns the value of the link at the back of the deque
{
    assert( myDeque!= NULL );
    return myDeque->last->value;
}

void removeFrontDeque(Deque* myDeque)			// Removes the link at the front of the deque
{
    assert( myDeque!= NULL );
    myDeque->first=myDeque->first->next;
    free(myDeque->first->front);
    myDeque->first->front=NULL;
}

void removeBackDeque(Deque* myDeque)			// Removes the link at the back of the deque
{
    assert( myDeque!= NULL );
    myDeque->last=myDeque->last->front;
    free(myDeque->last->next);
    myDeque->last->next=NULL;
}

void printDeque(Deque* myDeque) 				// Prints the values of the links in the deque from front to back
{
    assert( myDeque!= NULL );
    if(isEmptyDeque(myDeque))
        printf("The Deque is empty.\n");
    else
    {
        Link* tmp;
        tmp=myDeque->first;
        while(tmp!=NULL)
        {
            printf("%d ",tmp->value);
            tmp=tmp->next;
        }
        printf("\n");
    }
}

/* ************************************************************************
	Bag Functions
************************************************************************ */
Bag* bagCreate()							// Allocates and initializes the bag.
{
    return linkedListCreate();
}

void deleteBag(Bag* myBag)					// Deallocates the data and deletes the bag
{
    deletelinkedList(myBag);
}

int sizeBag(Bag* myBag)			    		// Returns the size of the bag
{
    sizelinkedList(myBag);
}

int isBagEmpty(Bag* myBag)					// Returns "1" if the bag is empty or "0" if not
{
    return isEmptyLinkedList(myBag);
}

void addBag(Bag* myBag, TYPE value) 		// Adds an element into the bag
{
    addBackDeque(myBag, value);
}

int containsBag(Bag* myBag, TYPE value) 	// Returns "1" if the bag contains the specified element or "0" if not
{
    assert( myBag!= NULL );
    if(isEmptyLinkedList(myBag))
        return 0;
    else
    {
        Link* tmp;
        tmp=myBag->first;
        while(tmp!=NULL)
        {
            if(tmp->value==value)
                return 1;
            else
                tmp=tmp->next;
        }
        return 0;
    }
}

void removeBag(Bag* myBag, TYPE value)		// Removes the specific element from the bag
{
    assert( myBag!= NULL );
    if(isEmptyLinkedList(myBag))
        printf("The bag is empty.\n");
    else
        removeLink(myBag, value);
}

void printBag(Bag* myBag)					// Prints the values of the links in the bag from front to back
{
    printLinkedList(myBag);
}
