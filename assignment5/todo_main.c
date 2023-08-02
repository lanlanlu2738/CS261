/*
 * This is where you will develop your to-do list application using your priority queue
 * Name:Chieh Huang, Chan-Wei Yeh, Yu-Yang Ting
 * Email:huangc7@oregonstate.edu, yehcha@oregonstate.edu, tingy@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pq.h"
void print_f(struct pq* pq)
{
    if(pq==NULL)
    {
        printf("priority queue is not build yet.\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⣤⣴⣶⣾⣆⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠠⣤⣤⣤⠄⢤⣴⣶⣿⣿⣿⢟⣿⣿⣿⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⣀⣠⣤⡾⢏⢠⣶⣶⣾⡑⡀⢸⠋⠁⠄⢠⣾⣿⣿⣿⠄⠄⠄⠄⠄\n");
        printf("⠄⢀⣠⣶⣿⣿⣿⠟⠁⠁⠰⣋⢫⢲⡇⠛⠄⠄⢀⣠⣤⣉⠻⠿⠿⠄⠄⠄⠄⠄\n");
        printf("⢰⣿⣿⣟⣋⣉⣁⠄⠄⠄⠄⠻⣆⣂⡕⠼⠂⠉⣿⣿⡇⢏⠉⠉⠁⠄⠄⠄⠄⠄\n");
        printf("⠄⠙⢿⣿⣿⣿⣿⠃⢸⢋⡁⢊⠒⣲⡶⠊⢁⣴⣿⣿⣿⣦⣦⠄⠄⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠙⠻⣿⡟⠄⡆⢸⣧⣾⣶⣤⣤⣾⡿⣿⣿⠿⡻⣻⣿⠁⠄⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠘⠠⣾⣿⣿⡿⠿⠿⣥⣾⣿⠿⣛⠅⢰⣗⠄⠄⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠸⣶⣶⣿⣟⣛⣛⣛⠲⠿⣵⣿⣟⢅⠂⠄⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢹⡟⠋⣠⣤⣤⣤⣍⡑⠂⠬⢉⣾⠄⠄⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢠⠁⣿⣿⣿⣿⠿⠿⠿⠿⠷⢶⡄⠄⠄⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⠄⢉⣁⣀⣤⣤⣤⣤⣤⣤⣤⠄⠄⠄⠄⠄⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⠈⠙⠿⣿⣿⣿⣿⡍⠟⢁⣠⣤⣶⣶⣤⣄⡀⠄⠄⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⠄⢀⣾⣿⣿⣷⣦⣀⠉⠿⣿⡇⠄⣾⣿⣿⣿⣿⣿⣿⣿⣶⡀⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⢠⣾⣿⣿⣿⣿⣿⣿⣷⡄⠹⠇⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄\n");
        printf("⠄⠄⠄⠄⠄⠄⣾⣿⣿⣿⣿⣿⣿⣿⡿⠋⠄⠄⠈⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⡇\n");
        printf("priority queue is not build yet.\n");
        return ;
    }
    printPq(pq);
    return ;
}

void print_application()
{
    printf("** TO-DO LIST APPLICATION **\n\n");
    printf("Press:\n");
    printf("'h' help\n");
    printf("'c' to create a new file\n");
    printf("'l' to load to-do list from a new list\n");
    printf("'s' to save to-do list to a file\n");
    printf("'a' to add a new task\n");
    printf("'g' to get the first task\n");
    printf("'r' to remove the first task\n");
    printf("'p' to print the list\n");
    printf("'e' to exit the program\n");
}

FILE* get_file_name()
{
    printf("Please enter the filename to load the list from:");
    char s[20];
    int n;
    gets(s);
    //printf("%s\n",s);
    FILE *ptr;
    ptr=fopen(s,"r+");
    if(ptr==NULL)
    {
        printf("Your file is not exist.\n");
        printf("Do you want to create a file with this name? yes type 1 or type other number to exit the program\n");
        scanf("%d",&n);
        if(n==1)
        {
            printf("Your file name is **%s**\n",s);
            ptr=fopen(s,"w+");
        }
        else
            exit(0);

    }
    else
        printf("The list has been loaded successfully!!!\n");
    return ptr;
}

FILE* create_new_file()
{
    printf("please enter a new name\n");
    char s[20];
    gets(s);
    FILE *ptr;
    ptr=fopen(s,"r+");
    if(ptr!=NULL)
    {
        printf("Your file has already existed.");
        printf("Loading your file success!!!\n");
        return ptr;
    }
    else
    {
        ptr=fopen(s,"w+");
        if(ptr!=NULL)
        {
            printf("Creating your file success!!!\n");
            printf("Loading your file success!!!\n");
            return ptr;
        }
    }
}

struct pq* load_list(FILE *ptr)
{
    struct pq* pq=createPq();

    char s[100];
    int n,sp,i,j,priority,k;
    while(fgets(s,sizeof(s),ptr))
    {
        //memset(s1,'\0',100);
        //memset(s2,'\0',4);
        //memset(s3,'\0',100);
        char *s1=malloc(sizeof(char)*100);
        char *s2=malloc(sizeof(char)*4);
        char *s3=malloc(sizeof(char)*100);
        priority=0;
        k=0;
        //printf("%s\n",s);
        n=strlen(s);
        for(i=n; i>=0; i--)
        {
            if(s[i]==' ')
            {
                sp=i;
                break;
            }
        }
        //printf("%d %d\n",n,sp);
        strncpy(s1,s,sp);
        s1[sp]='\0';
        //printf("%s\n",s1);
        strcpy(s3,s1);
        j=0;
        for(i=sp; i<n; i++)
        {
            if(s[i+1]>='0' && s[i+1]<='9')
            {
                s2[j]=s[i+1];
                j++;
            }

        }
        n=strlen(s2);
        if(s2[n-1]>'9' || s2[n-1]<'0')
            s2[n-1]='\0';
        //printf("Task discription:%s \n",s3);
        //printf("s2:%s\n", s2);
        n=strlen(s2);
        //printf("n:%d\n",n);
        for(i=n; i>0; i--)
        {
            k=1;
            for(j=1; j<i; j++)
            {
                k*=10;
            }
            priority+=(s2[n-i]-'0')*k;
        }
        //printf("Priority:%d\n",priority);
        addPq(pq, s3, priority);
    }

    return pq;
}

void savelist(struct pq* pq)
{
    FILE *ptr;
    char s[20],s1[100];
    if (pq==NULL)
    {
        pq=createPq();
    }
    int n=pqsize(pq);
    if(n==0)
    {
        printf("Your list is not loaded or empty.\n");
        return ;
    }
    printf("After saving, the program will stop and exit.\n");
    printf("Please enter the filename to save the list to:");
    gets(s);
    ptr=fopen(s,"w");
    for(int i=0; i<n; i++)
    {
        //printf("%s\n",(char *)node_value(pq));
        strcpy(s1,(char *)node_value(pq));
        fputs(s1, ptr);
        fputs(" ",ptr);
        sprintf(s1,"%d",node_priority(pq));
        fputs(s1, ptr);

        fputs("\n",ptr);
        //printf("before remove.\n");
        removePq(pq);
    }
    exit(0);
}

void addtask(struct pq* pq)
{
    printf("please input task:");
    char *s=malloc(sizeof(char)*100);
    gets(s);
    printf("please input priority:");
    int n;
    scanf("%d",&n);
    addPq(pq,s,n);

}

void getfirst(struct pq* pq)
{
    if(pqsize(pq)==0)
    {
        printf("Your list is empty.\n");
        return ;
    }
    printf("Your first task:%s\n",node_value(pq));
}

struct pq* printlist(struct pq* pq)
{
    char s[20],s1[100];
    if (pq==NULL || isemptyPq(pq)==1)
    {
        printf("list is empty or not loading.\n");
        return ;
    }
    int n=pqsize(pq);
    /*if(n==0)
    {
        printf("Your list is not loaded or empty.\n");
        return ;
    }*/
    struct pq* tmp=createPq();
    struct node* node=(struct node*)malloc(sizeof(node));
    for(int i=0; i<n; i++)
    {
        //printf("%s\n",(char *)node_value(pq));
        printf("Task:%s priority:%d.\n",node_value(pq),node_priority(pq));
        addPq(tmp,node_value(pq),node_priority(pq));
        /*strcpy(s1,(char *)node_value(pq));
        fputs(s1, ptr);
        fputs(" ",ptr);
        sprintf(s1,"%d",node_priority(pq));
        fputs(s1, ptr);

        fputs("\n",ptr);*/
        //printf("before remove.\n");
        removePq(pq);
    }
    return tmp;
}

void removetask(struct pq* pq)
{
    removePq(pq);
}

int main(int argc, char** argv)
{
    FILE *ptr;
    struct pq* priority_q;
    printf("Welcome TO-DO list program.\n");
    print_application();
    char c[2];
    while(gets(c)!=NULL)
    {
        switch(c[0])
        {
        case'f':
                print_f(priority_q);
            printf("press 'h' for help.\n");
            break;
        case'h':
            print_application();
            printf("press 'h' for help.\n");
            break;
        case'c':
                ptr=create_new_file();
            printf("press 'h' for help.\n");
            break;
        case'l':
            printf("loading to-do list from a new list\n");
            ptr=get_file_name();
            priority_q=load_list(ptr);
            printf("press 'h' for help.\n");
            //printPq(priority_q);
            break;
        case's':
            printf("saving to-do list\n");
            savelist(priority_q);
            printf("press 'h' for help.\n");
            break;
        case'a':
            printf("adding a new task\n");
            addtask(priority_q);
            printf("press 'h' for help.\n");
            break;
        case'g':
            printf("getting the first task\n");
            getfirst(priority_q);
            printf("press 'h' for help.\n");
            break;
        case'r':
            printf("removing the first task\n");
            removetask(priority_q);
            printf("press 'h' for help.\n");
            break;
        case'p':
            printf("printing the list\n");
            priority_q=printlist(priority_q);
            break;
        case'e':
                printf("exiting the program\n");
            return 0;
        default:
            if(strcmp(c,"\n"))
                break;
            else
            {
                printf("invalid input, please try again\n");
                printf("press 'h' for help.\n");
                break;
            }
        }
    }
    return 0;
}
