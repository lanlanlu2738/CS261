#include<stdio.h>
#include"linkedList.h"

int main()
{
    LinkedList *list;
    list=linkedListCreate();
    printf("The size of list is %d.\n",sizelinkedList(list));
    addLinkBefore(list, 1);
    addLinkBefore(list, 2);
    printLinkedList(list);
    addLinkBefore(list, 1);
    printLinkedList(list);
    removeLink(list, 3);
    removeLink(list, 1);
    printLinkedList(list);
    deletelinkedList(list);

    Deque *myDeque;
    myDeque=dequeCreate();
    printf("The size of deque is %d.\n",sizeDeque(myDeque));
    addBackDeque(myDeque, 3);
    addBackDeque(myDeque, 4);
    addFrontDeque(myDeque, 5);
    printf("The front of myDeque is %d.\n",frontDeque(myDeque));
    printf("The back of myDeque is %d.\n", backDeque(myDeque));
    printDeque(myDeque);
    removeBackDeque(myDeque);
    removeBackDeque(myDeque);
    printf("The front of myDeque is %d.\n",frontDeque(myDeque));
    printf("The back of myDeque is %d.\n", backDeque(myDeque));
    printDeque(myDeque);

    Bag *bag;
    bag=bagCreate();
    addBag(bag, 5);
    addBag(bag, 2);
    addBag(bag, 5);
    for(int i=0; i<10; i++)
    {
        addBag(bag, i);
    }
    printf("The size of bag is %d.\n",sizeBag(bag));
    printBag(bag);
    if(containsBag(bag, 2)==1)
        printf("The bag contains 2.\n");
    else
        printf("The bag doesn't contains 2.\n");
    removeBag(bag, 2);
    if(containsBag(bag, 2)==1)
        printf("The bag contains 2.\n");
    else
        printf("The bag doesn't contains 2.\n");
    printBag(bag);

}
