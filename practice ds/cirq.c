//The Program for Circular Queue
//written by Dr. B K Swain
#include<stdio.h>
#include<conio.h>
#define size 5
void cenq();
void cdeq();
void ctrav();
int f=-1,r=-1,cirQ[size];
int main()
{
int ch;
char opt;
//clrscr();
do{
 printf("\n Enter \n 1:enquing \n 2:deque \n 3:trav \n 4:Exit");
fflush(stdin);
scanf("%d",&ch);//1||2...
 switch(ch)
 {
 case 1:cenq();break;
 case 2:cdeq();break;
 case 3:ctrav();break;
 case 4:exit(0);
 }
 printf("\n Do you want to conti. press y/n");fflush(stdin);
 scanf("%c",&opt);//y||n
}while(opt !='n'); 
return 0;
}//main ends
void cenq()
{
int v;
printf("\n Enter the value");
scanf("%d",&v);
if(f==-1 && r==-1)
{ f=r=0;
cirQ[r]=v;
printf("\n enqued");
}
else if((r<size-1) && (f<=r))
{
r++;
cirQ[r]=v;
printf("\n Enqued");
}
else if(f>0)
{
int i;
for(i=0;i<size;i++)
{
if(cirQ[i]==0)
{
r=i;
cirQ[r]=v;
printf("\n Enqued");
break;
}
else 
printf("\n Overflow");
}
}
} //end cenq()
void ctrav()
{
int i;
for(i=0;i<size;i++)
printf(" %d",cirQ[i]);
} //end ctrav()
void cdeq()
{
int i;
if(f==-1 && r==-1)
printf("\n Underflow");
else if(f>r)
{
for(i=f;i<size;i++)
{
if(cirQ[i]!=0)
{
cirQ[i]=0;
printf("\n Deleted");
f++;
}
}
}
}