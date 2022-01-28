#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct LL
{
int roll;
struct LL *add;
};
struct LL *f = NULL;
struct LL *create_ll(struct LL *);
struct LL *display(struct LL *);
struct LL *insert_beg(struct LL *);
struct LL *insert_end(struct LL *);
struct LL *insert_before(struct LL *);
struct LL *insert_after(struct LL *);
struct LL *delete_beg(struct LL *);
struct LL *delete_end(struct LL *);
struct LL *delete_node(struct LL *);
struct LL *delete_after(struct LL *);
struct LL *delete_list(struct LL *);
struct LL *sort_list(struct LL *);
int main(int argc, char *argv[]) {
int option;
do
{
printf("\n\n *****MAIN MENU *****");
printf("\n 1: Create a list");
printf("\n 2: Display the list");
printf("\n 3: Add a LL at the beginning");
printf("\n 4: Add a LL at the end");
printf("\n 5: Add a LL before a given LL");
printf("\n 6: Add a LL after a given LL");
printf("\n 7: Delete a LL from the beginning");
//176 roll Structures Using C
printf("\n 8: Delete a LL from the end");
printf("\n 9: Delete a given LL");
printf("\n 10: Delete a LL after a given LL");
printf("\n 11: Delete the entire list");
printf("\n 12: Sort the list");
printf("\n 13: EXIT");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1: f = create_ll(f);
printf("\n LINKED LIST CREATED");
break;
case 2: f = display(f);
break;
case 3: f = insert_beg(f);
break;
case 4: f = insert_end(f);
break;
case 5: f = insert_before(f);
break;
case 6: f = insert_after(f);
break;
case 7: f = delete_beg(f);
break;
case 8: f = delete_end(f);
break;
case 9: f = delete_node(f);
break;
case 10: f = delete_after(f);
break;
case 11: f = delete_list(f);
printf("\n LINKED LIST DELETED");
break;
case 12: f = sort_list(f);
break;
}
}while(option !=13);
getch();
return 0;
}
struct LL *create_ll(struct LL *f)
{
struct LL *mem, *h;
int rn;
printf("\n Enter -1 to end");
printf("\n Enter the roll : ");
scanf("%d", &rn);
while(rn!=-1)
{
mem = (struct LL*)malloc(sizeof(struct LL));
mem -> roll=rn;
if(f==NULL)
{
mem -> add = NULL;
f = mem;
}
else
{
h=f;
//Linked Lists 177
while(h->add!=NULL)
h=h->add;
h->add = mem;
mem->add=NULL;
}
printf("\n Enter the roll : ");
scanf("%d", &rn);
}
return f;
}
struct LL *display(struct LL *f)
{
struct LL *h;
h = f;
while(h != NULL)
{
printf("\t %d", h -> roll);
h = h -> add;
}
return f;
}
struct LL *insert_beg(struct LL *f)
{
struct LL *mem;
int rn;
printf("\n Enter the roll : ");
scanf("%d", &rn);
mem = (struct LL *)malloc(sizeof(struct LL));
mem -> roll = rn;
mem -> add = f;
f = mem;
return f;
}
struct LL *insert_end(struct LL *f)
{
struct LL *h, *mem;
int rn;
printf("\n Enter the roll : ");
scanf("%d", &rn);
mem = (struct LL *)malloc(sizeof(struct LL));
mem -> roll = rn;
mem -> add = NULL;
h = f;
while(h -> add != NULL)
h = h -> add;
h -> add = mem;
return f;
}
struct LL *insert_before(struct LL *f)
{
struct LL *mem, *h, *preptr;
int rn, val;
printf("\n Enter the roll : ");
scanf("%d", &rn);
printf("\n Enter the value before which the roll has to be inserted : ");
scanf("%d", &val);
mem = (struct LL *)malloc(sizeof(struct LL));
mem -> roll = rn;
h = f;
while(h -> roll != val)
{
//178 roll Structures Using C
preptr = h;
h = h -> add;
}
preptr -> add = mem;
mem -> add = h;
return f;
}
struct LL *insert_after(struct LL *f)
{
struct LL *mem, *h, *preptr;
int rn, val;
printf("\n Enter the roll : ");
scanf("%d", &rn);
printf("\n Enter the value after which the roll has to be inserted : ");
scanf("%d", &val);
mem = (struct LL *)malloc(sizeof(struct LL));
mem -> roll = rn;
h = f;
preptr = h;
while(preptr -> roll != val)
{
preptr = h;
h = h -> add;
}
preptr -> add=mem;
mem -> add = h;
return f;
}
struct LL *delete_beg(struct LL *f)
{
struct LL *h;
h = f;
f = f -> add;
free(h);
return f;
}
struct LL *delete_end(struct LL *f)
{
struct LL *h, *preptr;
h = f;
while(h -> add != NULL)
{
preptr = h;
h = h -> add;
}
preptr -> add = NULL;
free(h);
return f;
}
struct LL *delete_node(struct LL *f)
{
struct LL *h, *preptr;
int val;
printf("\n Enter the value of the LL which has to be deleted : ");
scanf("%d", &val);
h = f;
if(h -> roll == val)
{
f = delete_beg(f);
return f;
}
else
{
//Linked Lists 179
while(h -> roll != val)
{
preptr = h;
h = h -> add;
}
preptr -> add = h -> add;
free(h);
return f;
}
}
struct LL *delete_after(struct LL *f)
{
struct LL *h, *preptr;
int val;
printf("\n Enter the value after which the LL has to deleted : ");
scanf("%d", &val);
h = f;
preptr = h;
while(preptr -> roll != val)
{
preptr = h;
h = h -> add;
}
preptr -> add=h -> add;
free(h);
return f;
}
struct LL *delete_list(struct LL *f)
{
struct LL *h; // Lines 252-254 were modified from original code to fix unresposiveness in output window
if(f!=NULL){
h=f;
while(h != NULL)
{
printf("\n %d is to be deleted add", h -> roll);
f = delete_beg(h);
h = f;
}
}
return f;
}
struct LL *sort_list(struct LL *f)
{
struct LL *ptr1, *ptr2;
int temp;
ptr1 = f;
while(ptr1 -> add != NULL)
{
ptr2 = ptr1 -> add;
while(ptr2 != NULL)
{
if(ptr1 -> roll > ptr2 -> roll)
{
temp = ptr1 -> roll;
ptr1 -> roll = ptr2 -> roll;
ptr2 -> roll = temp;
}
ptr2 = ptr2 -> add;
}
ptr1 = ptr1 -> add;
//180 roll Structures Using C
}
return f; // Had to be added
}