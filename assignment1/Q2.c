/* CS261- Assignment 1A - Question 2
   Name:Chieh Huang
   Date:27/9/2022
   Solution description:
   4.
   No, there is no different.
   The skeleton function will copy the value and store it to another address.
   No, they are still same.
   Because we use int * to receive the address.
   The address in main function will not be change by this.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c)
{
    // Swap the addresses stored in the pointer variables a and b
    //printf("print a:%p b:%p\n",&a,&b);
    int *tmp;
    tmp=a;
    a=b;
    b=tmp;
    //printf("print a:%p b:%p\n",&a,&b);
    // Decrement the value of integer variable c
    c--;
    // Return c
    return c;
}

int main()
{
    // Declare three integers x,y and z and initialize them randomly to values in [0,10]
    int x,y,z,re;
    time_t t;
    srand((unsigned)time(&t));
    x=rand() % 11;
    y=rand() % 11;
    z=rand() % 11;

    // Print the values of x, y and z
    //printf("x:%p y:%p z:%p\n",&x,&y,&z);
    printf("Before change:x:%d y:%d z:%d\n",x,y,z);
    // Call foo() appropriately, passing x,y,z as parameters
    re=foo(&x,&y,z);

    // Print the values of x, y and z
    //printf("x:%p y:%p z:%p\n",&x,&y,&z);
    printf("After change:x:%d y:%d z:%d\n",x,y,z);
    // Print the value returned by foo
    printf("value returned by foo:%d\n",re);


    return 0;
}




