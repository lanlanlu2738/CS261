/* CS261- Assignment 1A - Question 0
   Name:Chieh Huang
   Date:2022/9/26
   Solution description:
   3.
   No, it is changed.
   In fooA, I assign the reference of x to *iptr, so the value of *iptr will point to the value of x.
   If I change the value of *Iptr, the value of x will be change as well.
   Then what is &iptr?
   We announce int *iptr. It is a datatype different to int x;
   &iptr is the address of iptr which stores x's address, and *iptr will point to the value of x;
   5.
   No, It doesn't change.
   In 3., I know the relation among &jptr, *jptr ,jptr and x.
   I write a "jptr--" to change the address pointed to by jptr, so *iptr will point to a unknown value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr)
{
    printf("\n-----IN FOOA-----\n");
    // Print the value and address of the integer pointed to by iptr
    printf("The value: %d\n",*iptr);
    printf("The address: %p\n",iptr);

    // Increment the value of the integer pointed to by iptr by 5
    (*iptr)+=5;
    printf("The value+5: %d\n",*iptr);
    //printf("The address: %p\n",iptr);

    // Print the address of iptr itself
    printf("The address of iptr: %p\n", &iptr);
    return;
}


void fooB(int* jptr)
{
    printf("\n-----IN FOOB-----\n");

    // Print the value and address of the integer pointed to by jptr
    printf("The value:%d\n",*jptr);
    printf("The address:%p\n",jptr);
    printf("The address of jptr: %p\n", &jptr);

    // Decrement jptr by 1
    jptr--;
    //printf("The value:%d\n",*jptr);
    //printf("The address: %p\n",jptr);
    printf("The value after changing:%d\n",*jptr);
    printf("The address after changing:%p\n",jptr);
    // Print the address of jptr itself
    printf("The address of jptr after changing: %p\n", &jptr);
    return;
}


int main()
{

    // Declare an integer x and initialize it randomly to a value in [0,10]
    time_t t;
    int x;
    srand((unsigned)time(&t));
    x=rand() % 11;

    // Print the value and address of x
    printf("The value: %d\n",x);
    printf("The address: %p\n",&x);

    // Call fooA() with the address of x
    fooA(&x);

    // Print the value of x
    printf("\n-----IN MAIN-----\n");
    printf("The value: %d\n",x);

    // Call fooB() with the address of x
    fooB(&x);

    // Print the value and address of x
    printf("\n-----IN MAIN-----\n");
    printf("The value: %d\n",x);
    printf("The address: %p\n",&x);
    return 0;
}


