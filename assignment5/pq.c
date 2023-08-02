/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name:
 * Email:
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue
 */

struct pq
{
    struct dynarray* dyn_array;
};


/*
* Struct to store the elements of the priority queue
*/

struct node
{

    void* value;
    int priority;

};



/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */

pq* createPq()
{
    struct pq* new_queue=(struct pq*)malloc(sizeof(new_queue));
    assert(new_queue);
    new_queue->dyn_array=dynarray_create();
    return new_queue;
}


/*
 * This function should free the memory allocated to a given priority queue
 */

void freePq(pq* myPq)
{
    assert(myPq);
    free(myPq->dyn_array);
    free(myPq);
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 */

int isemptyPq(pq* myPq)
{
    if(dynarray_size(myPq->dyn_array)>0)
        return 0;
    else
        return 1;
}


/*
 * This function should add a given element into a priority queue with a
 * specified priority value.
 */

void addPq(pq* myPq, void* value, int priority)
{
    //printf("**in addpq**\n");
    struct node* new_node=(node*)malloc(sizeof(new_node));
    //printf("**new node**\n");
    new_node->priority = priority;
    //printf("priority: %d\n",new_node->priority);
    new_node->value = value;
    //printf("value:%s\n",(char*)new_node->value);
    dynarray_insert(myPq->dyn_array, new_node);
    //printf("**insert**\n");
    int idx=dynarray_size(myPq->dyn_array)-1;
    //printf("size:%d\n",idx);
    switch_Pq(myPq->dyn_array,idx);
    //printPq(myPq);
}

void switch_Pq(struct dynarray* da, int idx)
{
    //printf("**in switch_pq**\n");
    if(idx==0)
        return;
    else
    {
        struct node* tmp1=(struct node*)dynarray_get(da, idx);
        struct node* tmp2=(struct node*)dynarray_get(da, (idx-1)/2);
        if(tmp1->priority<tmp2->priority)
        {
            struct node* tmp=(struct node*)dynarray_get(da, idx);
            dynarray_set(da, idx, (struct node*)dynarray_get(da, (idx-1)/2));
            dynarray_set(da, (idx-1)/2, tmp);
            //da->data[idx]=(struct node*)dynarray_get(da, (idx-1)/2);
            //da->data[(idx-1)/2]=tmp;
        }
        else
            return;
    }
    switch_Pq(da, (idx-1)/2);
}


/*
 * This function should return the value of the item with lowest priority
 *
 */

void* getPq(pq* myPq)
{
    return dynarray_get(myPq->dyn_array, 0);
}


/*
 * This function should remove the value with lowest priority
 */

void removePq(struct pq* myPq)
{
    dynarray_set(myPq->dyn_array, 0, dynarray_get(myPq->dyn_array,dynarray_size(myPq->dyn_array)-1));

    //myPq->dyn_array->data[0]=myPq->dyn_array->data[dynarray_size(myPq->dyn_array)-1];
    dynarray_remove(myPq->dyn_array, dynarray_size(myPq->dyn_array)-1);
    int n=0;

    struct node* tmp1=(node *)dynarray_get(myPq->dyn_array,2*n+1);
    struct node* tmp2=(node *)dynarray_get(myPq->dyn_array,2*n+2);
    while(n<dynarray_size(myPq->dyn_array))
    {
        if(tmp1->priority<tmp2->priority && 2*n+1<dynarray_size(myPq->dyn_array))
        {
            struct node* tmp=(node *)dynarray_get(myPq->dyn_array,n);
            dynarray_set(myPq->dyn_array, n, tmp1);
            dynarray_set(myPq->dyn_array, 2*n+1, tmp);
            n=2*n+1;
        }
        else if(tmp1->priority>=tmp2->priority && 2*n+2<dynarray_size(myPq->dyn_array))
        {
            struct node* tmp=(node *)dynarray_get(myPq->dyn_array,n);
            dynarray_set(myPq->dyn_array, n, tmp2);
            dynarray_set(myPq->dyn_array, 2*n+2, tmp);
            n=2*n+2;
        }
        else
            break;
    }
}



/*
 * This function should print the values that are in the pq
 * and their priorities on the screen
 * from the queue.
 */

void printPq(struct pq* myPq)
{
    int n=dynarray_size(myPq->dyn_array);
    for(int i=0; i<n; i++)
    {
        struct node* tmp=(node*)dynarray_get(myPq->dyn_array ,i);
        printf("Task:%s Priority:%d\n",(char *)tmp->value,tmp->priority);
    }
}

int pqsize(struct pq* myPq)
{
    return dynarray_size(myPq->dyn_array);
}

char* node_value(struct pq* myPq)
{
    struct node* tmp=(node*)dynarray_get(myPq->dyn_array ,0);
    //printf("node value:%s\n",(char *)tmp->value);
    return (char*)tmp->value;
}

int node_priority(struct pq* myPq)
{
   struct node* tmp=(node*)dynarray_get(myPq->dyn_array ,0);
    return tmp->priority;
}

