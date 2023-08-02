/* CS261- Assignment 1A - Question 3
   Name: Chieh Huang
   Date: 28/9/2022
   Solution description:
   I add a function "bool begin_check(char c)" to help me checking the first letter.
   Please enter a string which is shorter than 1 million characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char toUpperCase(char ch)
{
    // Convert ch to upper case, assuming it is in lower case currently
    return ch-32;

}

char toLowerCase(char ch)
{
    // Convert ch to lower case, assuming it is in upper case currently
    return ch+32;
}

int stringLength(char s[])
{
    // Return the length of the string
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}


void camelCase(char* word)
{
    // Convert to camelCase
    int i,j;
    for(i=0,j=0;i<stringLength(word);i++,j++)
    {
        if(word[i]=='_')
        {
            i++;
            word[j]=toUpperCase(word[i]);
        }
        else
        {
            word[j]=word[i];
        }
    }
    for(;j<=i;j++)
    {
        word[j]='\0';
    }
    //printf("%s\n",word);
    //printf("%d\n",stringLength(word));
    return;
}

bool begin_check(char c)
{
    if(c>='A'&&c<='Z')
    {
        c=toLowerCase(c);
        return true;
    }
    else if(c>='a'&&c<='z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    // Read the string from the keyboard
    bool begin=false;
    int c,i=0,check=0;
    char s[1000000];
    /*c=getc(stdin);
    printf("%c",c);
    s*/
    printf("please enter input:");
    while((c=getc(stdin))!=EOF)
    {
        if(c=='\n')
            break;
        if(begin==true)
        {
            if(c>='A'&&c<='Z')
            {
                c=toLowerCase(c);
                s[i]=c;
                i++;
                s[i]='\0';
                continue;
            }
            else if(c>='a'&&c<='z')
            {
                s[i]=c;
                i++;
                s[i]='\0';
                continue;
            }
            else
            {
                if(s[i-1]=='_')
                    continue;
                else
                {
                    s[i]='_';
                    i++;
                    s[i]='\0';
                }
            }
        }
        else
        {
            if(begin_check(c)==true)
            {
                s[i]=c;
                i++;
                s[i]='\0';
                begin=true;
            }
            else
                continue;
        }
        //camelCase(s);
        //printf("%d\n",stringLength(s));
    }
    if(s[stringLength(s)-1]=='_')
    {
        s[stringLength(s)-1]='\0';
    }
    for(i=0;i<stringLength(s);i++)
    {
        if(s[i]=='_')
            check++;
    }
    if(check<1)
    {
        printf("invalid input string\n");
        return 0;
    }
    //printf("%s\n",s);
    /*aif(s[i-1]<'A' && s[i-1]>'Z')
    {
        if(s[i-1]<'a' && s[i-1]>'z')
        {
            s[i-1]='\0';
        }
    }*/

    // Call camelCase
    camelCase(s);

    // Print the new string
    printf("%s\n",s);


    return 0;
}

