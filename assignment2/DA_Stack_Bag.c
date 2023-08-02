// DA_Stack_Bag.c: Dynamic Array, Stack and Bag implementations
#include <assert.h>
#include <stdlib.h>
#include "DA_Stack_Bag.h"


/* ************************************************************************
	Struct DynArr
************************************************************************ */
struct DynArr
{
    TYPE* data;
    int size;
    int capacity;
};

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */
DynArr* newDynArr(int cap)
{
    assert( cap >= 0 );
    DynArr* arr = (DynArr*) malloc(sizeof(arr));
    assert( arr != NULL );
    arr->capacity = cap;
    arr->size = 0;
    arr->data = (TYPE*) malloc(sizeof(TYPE)*cap);
    assert(arr->data != NULL);

    return arr;
};

void deleteDynArr(DynArr *myDA)
{
    assert(myDA != NULL && myDA->data != NULL);
    free(myDA->data);
    free(myDA);
};

int sizeDynArr(DynArr *myDA)
{
    assert(myDA!=NULL);
    return myDA->size;
};

void addDynArr(DynArr *myDA, TYPE value)
{
    int n;
    assert(myDA != NULL && myDA->data != NULL);
    if(myDA->size >= myDA->capacity)
    {
        n=myDA->capacity;
        //deleteDynArr(myDA);
        //myDA=newDynArr(n*2);
    }
    myDA->data[myDA->size]=value;
    myDA->size++;
};

TYPE getDynArr(DynArr *myDA, int position)
{
    assert(myDA != NULL && sizeDynArr(myDA)!=0);
    assert(position>=0 && position<sizeDynArr(myDA));
    return myDA->data[position];
};

void putDynArr(DynArr *myDA, int position, TYPE value)
{
    assert(myDA != NULL);
    assert(position>=0 && position<sizeDynArr(myDA));
    myDA->data[position]=value;
};

void swapDynArr(DynArr *myDA, int idx_i, int  idx_j)
{
    assert(myDA != NULL);
    assert((idx_i>= 0 && idx_i<sizeDynArr(myDA)) && (idx_j>=0 && idx_j<sizeDynArr(myDA)));
            int tmp;
            tmp=myDA->data[idx_i];
            myDA->data[idx_i]=myDA->data[idx_j];
            myDA->data[idx_j]=tmp;
};

void removeAtDynArr(DynArr *myDA, int idx_i)
{
    assert(myDA != NULL);
    assert(idx_i>=0 && idx_i<sizeDynArr(myDA));
    for(; idx_i<(sizeDynArr(myDA)-1); idx_i++)
    {
        myDA->data[idx_i]=myDA->data[idx_i+1];
    }
    myDA->data[idx_i]=NULL;
    myDA->size--;
};
/* ************************************************************************
	Stack Interface Functions
************************************************************************ */
Stack *newStack(int capacity)							// Allocates and initializes the stack.
{
    assert(capacity>0);
    Stack* arr = (Stack*) malloc(sizeof(arr));
    assert( arr != NULL );
    arr->capacity = capacity;
    arr->size = 0;
    arr->data = (TYPE*) malloc(sizeof(TYPE)*capacity);
    assert(arr->data != NULL);
    return arr;
};

void deleteStack(Stack *myStack)						// Deallocate the data and deletes the stack
{
    assert(myStack != NULL && myStack->data != NULL);
    free(myStack->data);
    free(myStack);
};

int sizeStack(Stack *myStack)							// Returns the size of the stack
{
    assert(myStack!=NULL);
    return myStack->size;
};

int isStackEmpty(Stack *myStack)						// Returns "1" if the stack is empty or "0" if not
{
    assert(myStack!=NULL);
    if(sizeStack(myStack)==0)
        return 1;
    else
        return 0;
};

void pushStack(Stack *myStack, TYPE value)				// Push an element onto the top of the stack
{
    assert(myStack!=NULL);
    //assert((myStack->capacity)>sizeStack(myStack));
    myStack->data[sizeStack(myStack)]=value;
    myStack->size++;
};

TYPE topStack(Stack *myStack)						// Returns the element at the top of the stack
{
    assert(myStack!=NULL);
    return myStack->data[sizeStack(myStack)-1];
};

void popStack(Stack *myStack)
{
    assert(myStack!=NULL);
    if(isStackEmpty(myStack)==1)
        printf("empty\n");
    else
    {
        myStack->size--;
    }
};

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */
Bag *newBag(int capacity)								// Allocates and initializes the bag.
{
    assert(capacity>0);
    Bag* arr = (Bag*) malloc(sizeof(arr));
    assert( arr != NULL );
    arr->capacity = capacity;
    arr->size = 0;
    arr->data = (TYPE*) malloc(sizeof(TYPE)*capacity);
    assert(arr->data != NULL);
    return arr;
};

void deleteBag(Bag *myBag)								// Deallocate the data and deletes the bag
{
    assert(myBag != NULL && myBag->data != NULL);
    free(myBag->data);
    free(myBag);
};

int sizeBag(Bag *myBag)								// Returns the size of the bag
{
    assert(myBag!=NULL);
    return myBag->size;
};

int isBagEmpty(Bag *myBag)							// Returns "1" if the bag is empty or "0" if not
{
    assert(myBag!=NULL);
    if(myBag->size==0)
        return 1;
    else
        return 0;
};

void addBag(Bag *myBag, TYPE value)					// Adds an element into the bag
{
    assert(myBag!=NULL);
    //assert(myBag->capacity>sizeStack(myBag));
    myBag->data[sizeBag(myBag)]=value;
    myBag->size++;
};

int containsBag(Bag *myBag, TYPE value)				// Returns "1" if the bag contains the specified element or "0" if not
{
    assert(myBag!=NULL);
    for(int i=0;i<sizeBag(myBag);i++)
    {
        if(myBag->data[i]==value)
            return 1;
    }
    return 0;
};

void removeBag(Bag *myBag, TYPE value)				// Remove the specific element from the bag and shifts all the following elements back one spot to fill the gap
{
    assert(myBag!=NULL);
    for(int i=0;i<sizeBag(myBag);i++)
    {
        if(myBag->data[i]==value)
        {
            for(int j=i;j<sizeBag(myBag)-1;j++)
            {
                myBag->data[j]=myBag->data[j+1];
            }
            myBag->size--;
        }
    }
};
