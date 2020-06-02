#include <stdio.h>
#include <stdlib.h>
//Goal: Manipulate simple chained list.Include element, remove, search, sort and print.
typedef struct nod
{
	int num;
	struct nod* next;
}Nod;
Nod* create()
{
	Nod* newone=NULL;
	return newone;
}
Nod* allocate()
{
	Nod*newone=(Nod*) malloc(sizeof(Nod));
	return newone;
}
Nod* beginninginsert(Nod*list,int value)
{
	Nod* allocated=allocate();
	allocated->num=value;
	if(list==NULL)
	{
		allocated->next=NULL;
		list=allocated;
	}
	else
	{
		allocated->next=list;
		list=allocated;
	}
	return list;
	
}
Nod* endinsert(Nod* list,int value)
{
	Nod* allocated=allocate();
	allocated->num=value;
	if(list==NULL)
	{
		allocated->next=NULL;
		list=allocated;
	}
	else
	{
		Nod* help=list;
		while(help->next!=NULL)
		{
			help=help->next;
		}
		help->next=allocated;
		allocated->next=NULL;
	}
	return list;
}
Nod* searchfor(Nod* list, int value)
{
	Nod* help;
	for(help=list;help!=NULL;help=help->next)
	{
		if(help->num==value)
		{
			return help;
		}
	}
	return NULL;
}
Nod* element_remove(Nod* list, int value) 
{
	Nod* prev=NULL; 
	Nod* help=list; 
	while(help!=NULL && help->num!=value)
	{
		prev=help;
		help=help->next;
	}
	if(help==NULL) 
	{
		return list;
	}
	if(prev==NULL) 
	{
		list=help->next;
	}
	else 
	{
		prev->next=help->next; 
	}
	return list;
}
Nod* sort(Nod* list) 
{
	Nod* p=list;
	Nod* j;
	int help;
	for(p=list;p!=NULL;p=p->next)
	{
		for(j=p->next;j!=NULL;j=j->next)
		{
			if(p->num>j->num)
			{
				help=j->num;
				j->num=p->num;
				p->num=help;
			}
		}
	}
	return list;
}
void print_out(Nod* list)
{
	Nod* help;
	for(help=list;help!=NULL;help=help->next)
	{
		printf(" %d ",help->num);
	}
}
int main()
{
  Nod* list=create();
  Nod* element;
  int option,q,value,i;	
  do
  {
  	printf("\n\n enter an option:\n 1 - to insert element at the beginning \n 2- to isere element at the end \n 3- to search for an element\n 4 - to withdraw a value\n 5- to sort the list\n 6- to print the list\n or zero to exit\n");
  scanf("%d",&option);
  switch(option)
  {
  	case 1: printf("enter the amount of element that you want to insert");
  	        scanf("%d",&q);
  	        for(i=0;i<q;i++)
  	        {
  	        	printf("enter an integer");
  	        	scanf("%d",&value);
  	        	list=beginninginsert(list,value);
  	        }
  	        break;
  	 case 2: printf("enter the amount of element that you want to insert");
	         scanf("%d",&q); 
			 for(i=0;i<q;i++)
			 {
			 	printf("enter an integer");
			 	scanf("%d",&value);
			 	list=endinsert(list,value);
			 }  
			 break;
	 case 3: printf ("enter an element to be searched for");
	         scanf("%d",&value);
			 element=searchfor(list,value);
			 if(element==NULL)
			 {
			 	printf("element not found");
			 }
			 else
			 {
			 	printf("element %d was found at address %x",element->num, element);
			 }
			 break;
	 case 4: printf("enter the element to be removed");
	         scanf("%d",&value);
	         list=element_remove(list,value);
	         break;
	        
	case 5: list=sort(list);
	        break;

  	default: print_out(list);  
  	}
  }while(option!=0);
}