/*
 * This file contains the definition of the interface for the priority queue
 * you'll implement.
*/
#ifndef __PQ_H
#define __PQ_H
#include "dynarray.h"


/*
 * Structure used to represent a priority queue.
 */

typedef struct pq pq;
typedef struct node node;
/*
 * Priority queue interface function prototypes.  Refer to pq.c for
 * documentation about each of these functions.
 */

pq* createPq();
void freePq(pq* myPq);
int isemptyPq(pq* myPq);
void addPq(pq* myPq, void* value, int priority);
void switch_Pq(struct dynarray* da, int idx);
void* getPq(pq* myPq);
void removePq(pq* myPq);
void printPq(pq* myPq);
int pqsize(struct pq* myPq);


#endif
