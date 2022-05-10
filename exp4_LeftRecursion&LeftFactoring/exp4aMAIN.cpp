/*
AIM: A program for Elimination of Left Recursion.


ALGORITHM:

-Start the program.

-Initialize the arrays for taking input from the user.

-Prompt the user to input the no. of non-terminals having left recursion and no. of productions for these non-terminals.

-Prompt the user to input the production for non-terminals.

-Eliminate left recursion using the following rules:- A->Aα1| Aα2 | . . . . . |Aαm A->β1| β2|    | βn
-Then replace it by

A-> βi A’ i=1,2,3,.....m A’-> αj A’ j=1,2,3,.    n A’-> Ɛ

-After eliminating the left recursion by applying these rules, display the productions without left recursion.

-Stop.

RESULT :

A program for Elimination of Left Recursion was run successfully.


*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    char a[10],b[50][10]={""},d[50][10]={""},ch;
    int i,n,c[10]={0},j,k,t,n1;
    printf("\nEnter the NON TERMINALS: ");
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the number of productions for %c : ",a[i]);
        scanf("%d",&c[i]);
    }
    t=0;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the productions for %c",a[i]);
        k=t;
        for(j=0;j<c[i];j++)
        {
            printf("\n%c->",a[i]);
            do
            {
                scanf("%s",b[k]);
                k++;
            }while(k<j);
        }
        t=t+10;
    }
    t=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==b[t][0])
        {
            n1=strlen(b[t]);
            for(k=1;k<n1;k++)
            {
                d[t][k-1]=b[t][k];
            }
        }
        t=t+10;
    }
    t=0;
    printf("\n\nThe resulting productions after eliminating Left Recursion are : \n");
    for(i=0;i<n;i++)
    {
        if(a[i]==b[t][0])
        {
            for(j=1;j<c[i];j++)
            {
                printf("\n%c -> %s%c'",a[i],b[t+j],a[i]);
            }
        }
        t=t+10;
    }
    t=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==b[t][0])
            printf("\n%c' -> %s%c'|%c",a[i],d[t],a[i],(char)238);
        else
            for(j=0;j<c[i];j++)
                printf("\n%c -> %s",a[i],b[t+j]);
        t=t+10;
    }
    return 0;
}
