/* CS261- Assignment 1A - Question 1
   Name:Chieh Huang
   Date:26/9/2022
   Solution description:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct student
{
    int id;
    int score;
};

struct student* allocate()
{
    // Allocate memory for ten students*/
    struct student *stud=(struct student*)malloc(10*sizeof(struct student));

    // Return the pointer*/
    return stud;
}

void generate(struct student* students)
{
    /* Generate random and unique IDs and random scores for ten students,
    IDs being between 1 and 10, scores between 0 and 100 */
    int i,j,num;
    struct student *tmp;
    time_t t;
    srand((unsigned)time(&t));
    for(i=0; i<10; i++,tmp++)
    {
        do
        {
            tmp=students;
            num=rand()%10+1;
            for(j=0; j<i; j++)
            {
                if(tmp->id==num)
                    break;
                tmp++;
            }
        }
        while(j!=i);
        tmp->id=num;
        tmp->score=rand()%101;
        //printf("id:%d score:%d\n",tmp->id,tmp->score);
    }
    return ;
}

void output(struct student* students)
{
    /* Output information about the ten students in the format:
       ID1 Score1
       ID2 score2
       ID3 score3
       ...
       ID10 score10*/
    int i=10;
    struct student *tmp;
    tmp=students;
    while(i--)
    {
        printf("ID%d:%d Score%d:%d\n",10-i,tmp->id,10-i,tmp->score);
        tmp++;
    }
}

void summary(struct student* students)
{
    /* Compute and print the minimum, maximum and average scores of the
    ten students */
    int i=10,sum=0,min=1000,max=0;
    struct student *tmp;
    tmp=students;
    while(i--)
    {
        if(tmp->score>max)
            max=tmp->score;
        if(tmp->score<min)
            min=tmp->score;
        sum+=tmp->score;
        tmp++;
    }
    printf("\nminimum:%d maximun:%d average:%d\n",min,max,sum/10);
    return;

}

void deallocate(struct student* stud)
{
    // Deallocate memory from stud
    if(stud!=NULL)
    {
        //printf("stud is not NULL\n");
        free(stud);
    }
    return;
}

int main()
{
    struct student* stud = NULL;

    // Call allocate
    stud=allocate();
    //printf("allocate finish\n");
    // Call generate
    generate(stud);
    //printf("generate finish\n");
    // Call output
    output(stud);

    // Call summary
    summary(stud);

    // Call deallocate
    deallocate(stud);

    return 0;
}

