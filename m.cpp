#include <stdio.h>
int main()
{
    int i,j;
	int matriz[5] [5];
	for (i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		
	
		 printf("entre com um valor para linha %d e coluna %d\n",i+1,j+1);
		 scanf("%d",&matriz[i] [j]);
	      
		}
		
	    
	}
	for (i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		
	
		 printf(" %d",matriz[i] [j]);
		 
	      
		}
		
	    printf("\n");
	}
    
    return 0;

}